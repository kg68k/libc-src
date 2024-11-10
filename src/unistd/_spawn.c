/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution from hupairlib by K.Abe (Abechan).
 * --------------------------------------------------------------------
 * $Id: _spawn.c,v 1.5 1994/11/27 13:10:08 mura Exp $
 */

/* System headers */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xsignal.h>
#include <sys/xstart.h>
#include <sys/xunistd.h>

/* Macros */
#define INITIAL_BUFSIZ 1024
#define STDFDS 5

/* External variables */
int _hugearg = _HUGEARG_DEFAULT;
int _keep_cwd_on_exec = 1;
char *_hugearg_indirect;

/* File scope variables */
static long nullenv[2] = {5, 0};

/* break cehck save */
static int obreak;

/* Structures and unions */
enum exec_mode {
    EXEC_LOADEXEC = 0,
    EXEC_LOAD,
    EXEC_PATHCHK,
    EXEC_LOADONLY,
    EXEC_EXECONLY,
    EXEC_BINDNO,
};

/* File scope functios */
static int indirect_create (char *arg, char *buffer)
{
    int fd;
    char *dir;
    char *iname;

    /* テンプレート文字列作成 */
    if ((dir = getenv ("temp")) == 0) {
	strcpy (buffer, "#exeXXXXXX");
    }
    else {
	_addlastsep (strcpy (buffer, dir));
	_tobslash (strcat (buffer, "#exeXXXXXX"));
    }

    /* インダイレクトファイル名を作成 */
    if ((int) (iname = mktemp (buffer)) < 0)
	return -1;

    /* インダイレクトファイルを作成 */
    if ((fd = open (iname, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0)
	return -1;

    /* 内容を書き込む */
    if (write (fd, arg, strlen (arg)) < 0) {
	close (fd);
	unlink (iname);
	return -1;
    }

    /* ファイルをクローズして終わり */
    close (fd);

    /* 成功 */
    return 0;
}

/* File scope functions */
static int indirect_exec (char *base, char *cmdline,
			  struct _dregs *regptr, const char *argv0)
{
    int rc;
    char iname[PATH_MAX + 1];

    /* インダイレクトファイルを作成する */
    if (indirect_create (cmdline + 1, iname) < 0) {
	_noexec_return (regptr);
	errno = EINVAL;
	return -1;
    }

    /* 実際にコマンドラインに渡す文字列を作成する */
    strcat (strcpy (cmdline + 1, base), iname);
    cmdline[0] = strlen (cmdline + 1) & 255;

    /* 本来の break に */
    _dos_breakck (obreak);

    /* プログラムを実行する */
    rc = _exec (EXEC_EXECONLY, regptr->a4, (long) cmdline, regptr->a3, regptr);

    /* 子が break を変えた時の為 */
    obreak = _dos_breakck (-1);
    _dos_breakck (2);

    /* インダイレクトファイルを削除する */
    unlink (iname);

    /* エラーチェック */
    if (rc < 0) {
	errno = _errcnv (rc);
	return -1;
    }

    /* 成功 */
    return 0;
}

/* File scope functios */
static char *copy_environ (char *const envp[])
{
    int envsize;
    char *dos_envbuf, *dos_envp, *q;
    char *const *ptr;

    /* envp がヌルならば environ を用いる */
    if (envp == 0)
	envp = (char **) environ;

    /* 環境エリアのトータルサイズを求める */
    for (ptr = envp, envsize = 4 + 1; *ptr; ptr++)
	envsize += strlen (*ptr) + 1;

    /* 偶数バンダリに調整する */
    envsize = (envsize + 1) & ~1;

    /* コピー先の領域を確保する */
    if ((dos_envbuf = malloc (envsize)) == 0)
	return 0;

    /* 先頭にバイト数を設定 */
    *(unsigned long *) dos_envbuf = envsize;

    /* 新しい環境エリアにすべてコピーする */
    for (ptr = envp, dos_envp = dos_envbuf + 4; *ptr; ptr++)
	for (q = *ptr; *dos_envp++ = *q++; );

    /* 最後をヌル文字で止める */
    *dos_envp++ = '\0';

    /* 新しい領域を返す */
    return dos_envbuf;
}

/* Functions */
int _spawn (int mode, const char *pathname,
	    char *const argv[], char *const envp[], int search_path)
{
    char *child_envp;						/* 子プロセスの環境 */
    char *cmdline = 0;						/* コマンドライン */
    char fpath[PATH_MAX + 1];					/* 実行パス名 */
    char cwd[PATH_MAX + 1];					/* カレントディレクトリ */
    const char *argv0;						/* 補正した argv[0] */
    int cmdlen;							/* コマンドラインの長さ */
    int rc = 0;							/* リターンコード */
    int exec_success = 0;					/* */
    int std_fds[STDFDS];					/* ファイルハンドル保存用 */
    struct _dregs regs;						/* 保存レジスタ */

    enum {
	JUST_BEGIN, AFTER_ENVSET, AFTER_ENCODE, AFTER_SIGEND
    } state = JUST_BEGIN;					/* 実行ステートフラグ */

#define RETURN(x) { rc = (x); goto bailout; }

    /*
    ** (1) エラーチェック及び準備
    */

    {
	/* 引数チェック */
	if (mode != P_WAIT && mode != P_OVERLAY) {
	    errno = EINVAL;
	    return -1;
	}

	/* _hugearg チェック */
	if (_hugearg != _HUGEARG_DEFAULT &&
	    _hugearg != _HUGEARG_FORCE &&
	    _hugearg != _HUGEARG_NOEXEC &&
	    _hugearg != _HUGEARG_INDIRECT) {
	    errno = EINVAL;
	    return -1;
	}

	/* 子プロセス用環境エリアを作成する */
	if ((child_envp = copy_environ (envp)) == 0)
	    RETURN (-1);

	/* ステートフラグ設定 */
	state = AFTER_ENVSET;
    }

    /*
    ** (2) 実行ファイル検索.....
    */

    {
	char tmparg[256];					/* テンポラリ */

	/* パス名をすべてスラッシュにする */
	_tobslash (strcpy (fpath, pathname));

	/* パスチェックを行う */
	if ((rc = _exec (EXEC_PATHCHK, (long) fpath, (long) tmparg,
			 (long) (search_path ? 0 : nullenv), &regs)) < 0) {
	    errno = _errcnv (rc);
	    RETURN (-1);
	}
    }

    /*
    ** (3) コマンドラインを HUPAIR エンコードして ARGV を作成する.....
    */

    {
	int bufsiz = INITIAL_BUFSIZ;				/* バッファサイズ */

	/* argv[0] の調整を行う */
	argv0 = argv[0] ? : pathname;

	/* コマンドライン生成用のバッファを確保する */
	if ((cmdline = malloc (bufsiz)) == 0)
	    RETURN (-1);

	/* argv を全部作成するまでループ */
	do {

	    /* コマンドラインを HUPAIR エンコードする */
	    if ((cmdlen = _enhupair (argv0, argv + 1,
				     cmdline + 8, bufsiz - 8)) < 0) {

		/* バッファが足りなければどんどん追加 */
		bufsiz += 1024;

		/* バッファ再割り当てを行う */
		if ((cmdline = realloc (cmdline, bufsiz)) == 0)
		    RETURN (-1);

	    }

	} while (cmdlen < 0);

    }

    /*
    ** (4) チェック用にプログラムをロードする.....
    */

    {
	int i;							/* カウンタ */

	/* ステートフラグ設定 */
	state = AFTER_ENCODE;

	/* ファイルハンドルを保存する */
	for (i = 0; i < STDFDS; i++)
	    if ((std_fds[i] = dup (i)) < 0)
		RETURN (-1);

	/* 割り込み停止 */
	_sigend ();

	/* 状態遷移 */
	state = AFTER_SIGEND;

	/* break を kill にする */
	obreak = _dos_breakck (-1);
	_dos_breakck (2);

	/* プログラムをロードする */
	rc = _exec (EXEC_LOAD, (long) fpath,
		    (long) cmdline + 8, (long) child_envp, &regs);

	/* エラー処理 */
	if (rc < 0) {
	    errno = _errcnv (rc);
	    RETURN (-1);
	}

	/* カレントディレクトリを保存する */
	if (_keep_cwd_on_exec)
	    getcwd (cwd, sizeof cwd);

    }

    /*
    ** (5) プログラムが HUPAIR かどうかでコマンドラインの渡し方を決める.....
    */

    {
	char *arg;						/* cmdline + 8 */
	char *hugearg;						/* HUGEARG の設定 */
	char *indstr;						/* indirect 文字列 */
	int ishupair;						/* HUPAIR フラグ */

	/* HUPAIR かどうか調べる */
	ishupair = (strcmp ((char *) regs.a4 + 2, "#HUPAIR") == 0);

	/* cmdline + 8 を求める */
	arg = (char *) regs.a2;

	/* HUPAIR あるいは 255 文字以内なら ... */
	if (ishupair || cmdlen <= 255) {

	force:

	    /* 本来の break に */
	    _dos_breakck (obreak);

	    /* プログラムを実行する */
	    rc = _exec (EXEC_EXECONLY, regs.a4, (long) arg, regs.a3, &regs);

	    /* 子が break を変えた時の為 */
	    obreak = _dos_breakck (-1);
	    _dos_breakck (2);

	    /* エラー処理 */
	    if (rc < 0) {
		errno = _errcnv (rc);
		RETURN (-1);
	    }

	}
	else {

	    /* 環境変数 HUGEARG を見る */
	    hugearg = getenv ("HUGEARG");

	    /* _hugearg によって決定 */
	    switch (_hugearg) {

	    case _HUGEARG_FORCE:

		/* 強制的に実行する */
		goto force;

	    case _HUGEARG_NOEXEC:

	    noexec:
		/* 実行失敗にする */
		_noexec_return (&regs);
		errno = E2BIG;
		RETURN (-1);

	    case _HUGEARG_INDIRECT:

		/* インダイレクト文字列が指定されていなければエラー */
		if (_hugearg_indirect == 0) {
		    _noexec_return (&regs);
		    errno = EINVAL;
		    RETURN (-1);
		}

		/* インダイレクト実行 */
		rc = indirect_exec (_hugearg_indirect, cmdline + 8, &regs, argv0);

		/* 次の処理へ */
		break;

	    case _HUGEARG_DEFAULT:

		/* HUGEARG が設定されていなければ実行失敗 */
		if (hugearg == 0)
		    goto noexec;

		/* HUGEARG = force ならば強制実行 */
		if (strcmp (hugearg, "force") == 0)
		    goto force;

		/* HUGEARG = indirect でなければ後はエラー */
		if (strncmp (hugearg, "indirect", 8) != 0)
		    goto noexec;

		/* インダイレクト文字列の取り出し */
		indstr = hugearg[8] ? &hugearg[9] : "-+-+-";

		/* インダイレクト実行 */
		rc = indirect_exec (indstr, cmdline + 8, &regs, argv0);

		/* 次の処理へ */
		break;

	    default:

		/* 該当しない場合はエラー */
		goto noexec;
	    }
	}

	/* 成功した? */
	exec_success = 1;

	/* カレントディレクトリを戻す */
	if (_keep_cwd_on_exec)
	    chdir (cwd);

    }

    /*
    ** (6) 後処理を行う
    */

    {
	int i;							/* カウンタ */

    bailout:

	/* 実行ステートに応じてメモリを解放する */
	switch (state) {

	case AFTER_SIGEND:

	    /* break フラグをに戻す */
	    _dos_breakck (obreak);

	    /* 割り込み再開 */
	    _siginit ();

	case AFTER_ENCODE:

	    /* 資源を解放する */
	    free (cmdline);

	    /* ファイルハンドルを戻す */
	    for (i = 0; i < STDFDS && std_fds[i] >= 0; i++) {
		dup2 (std_fds[i], i);
		close (std_fds[i]);
	    }

	case AFTER_ENVSET:

	    /* 環境を解放する */
	    free (child_envp);

	case JUST_BEGIN:

	    /* 次の処理へ */
	    break;

	}
    }

    /* オーバーレイの処理 */
    if (exec_success && mode == P_OVERLAY)
	exit (rc);

    /* リターンコードを戻す */
    return rc;
}
