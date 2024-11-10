/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: system.c,v 1.3 1994/05/02 16:53:08 mura Exp $
 */

/* System headers */
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/dos.h>
#include <sys/xglob.h>
#include <sys/xsignal.h>

/* Macros */
#define STDFDS 5
#define SYSTEM_ERR (127 << 8)

/* Functions */
int system (const char *cmdline)
{
    int i, len;
    int rc, interactive;
    char *shell = 0;
    char *shellopt = 0;
    char *shelltype = 0;
    enum {
	SHTYPE_COMMAND,
	SHTYPE_UNIX,
	SHTYPE_UNKNOWN
    } shtype;

    /* cmdline が 0 ならば対話的シェルを起動する */
    interactive = (cmdline == 0 || *cmdline == '\0');

    /* 対話的でない場合... */
    if (!interactive && (shell = getenv ("SYSTEM_SHELL")) != 0) {
	shelltype = getenv ("SYSTEM_SHELLTYPE");
	shellopt = getenv ("SYSTEM_SHELL_OPT");
    }
    else {
	shell = getenv ("SHELL");
	shellopt = getenv ("SHELL_OPT");
	shelltype = getenv ("SHELLTYPE");
    }

    /* シェルタイプが 0 ならば... */
    if (shelltype == 0) {

	/* シェルが設定されていれば... */
	if (shell) {

	    /* 設定値の長さを調べる */
	    len = strlen (shell);

	    /* 設定値を見る */
	    if ((len >= 7 && strcmpi (shell + len - 7, "command") == 0) ||
		(len >= 9 && strcmpi (shell + len - 9, "command.x") == 0))
		shtype = SHTYPE_COMMAND;

	    /* さもなくば UNIX タイプ... */
	    else
		shtype = SHTYPE_UNIX;

	}

	/* さもなくば COMMAND タイプ... */
	else
	    shtype = SHTYPE_COMMAND;

    }

    /* シェルタイプが規定されていれば... */
    else {

	/* 設定から判断 */
	if (strcmpi (shelltype, "COMMAND") == 0)
	    shtype = SHTYPE_COMMAND;
	else if (strcmpi (shelltype, "UNIX") == 0)
	    shtype = SHTYPE_UNIX;
	else
	    shtype = SHTYPE_UNKNOWN;

    }

    /* シェルタイプごとに... */
    switch (shtype) {

    case SHTYPE_COMMAND:

	/*
	** COMMAND.X は HUPAIR エンコードされたコマンドラインを受け取れ
	** ないので、HUPAIR なしで行う
	*/

	{
	    int std_fds[STDFDS];
	    char cmdshell[256];
	    char cwd[PATH_MAX + 1];
	    struct _comline comline;

	    /* 文字列を選択 */
	    if (shell == 0)
		shell = "COMMAND";
	    if (shellopt == 0)
		shellopt = "/C";

	    /* コマンドラインの長さチェック */
	    if ((strlen (shell) +
		 (interactive ? 0 : 2 /* space (0x20) x 2 */  +
		  strlen (shellopt) + strlen (cmdline))) > 255) {
		errno = E2BIG;
		return SYSTEM_ERR;
	    }

	    /* 文字列を構成する */
	    strcpy (cmdshell, shell);
	    if (!interactive) {
		strcat (cmdshell, " ");
		strcat (cmdshell, shellopt);
		strcat (cmdshell, " ");
		strcat (cmdshell, cmdline);
	    }

	    /* PATHCHK を行う */
	    if ((rc = _dos_pathchk (cmdshell, &comline, 0)) < 0) {
		errno = _errcnv (rc);
		return SYSTEM_ERR;
	    }

	    /* ファイルハンドルを保存 */
	    for (i = 0; i < STDFDS; i++) {
		if ((std_fds[i] = dup (i)) < 0) {
		    for (i--; i >= 0; i--)
			close (std_fds[i]);
		    return SYSTEM_ERR;
		}
	    }

	    /* カレントディレクトリを保存 */
	    if (_keep_cwd_on_exec)
		getcwd (cwd, sizeof cwd);

	    /* 割り込みを停止 */
	    _sigend ();

	    /* 実行させる */
	    rc = _dos_loadexec (cmdshell, &comline, 0);

	    /* 割り込みを再開する */
	    _siginit ();

	    /* カレントディレクトリを戻す */
	    if (_keep_cwd_on_exec)
		chdir (cwd);

	    /* ファイルハンドルを戻す */
	    for (i = 0; i < STDFDS; i++) {
		dup2 (std_fds[i], i);
		close (std_fds[i]);
	    }

	    /* エラーチェック */
	    if (rc < 0) {
		errno = _errcnv (rc);
		return SYSTEM_ERR;
	    }

	}

	break;

    case SHTYPE_UNIX:
    case SHTYPE_UNKNOWN:
    default:

	/* 対話的なら... */
	if (interactive)
	    rc = spawnlp (P_WAIT, shell, shell, 0);

	/* そうじゃなければ... */
	else {

	    /* オプション処理 */
	    if (shellopt == 0)
		shellopt = "-c";

	    /* 実行させる */
	    rc = spawnlp (P_WAIT, shell, shell, shellopt, cmdline, 0);

	}

	/* 失敗した? */
	if (rc == -1)
	    return SYSTEM_ERR;

	break;

    }

    /* 戻り値を返す */
    return rc;
}
