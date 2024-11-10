/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _libc.c,v 1.1.1.1 1993/04/18 16:17:18 mura Exp $
 */

/* System headers */
#include <stdio.h>
#include <sys/project.h>

/* Functions */
void _libc_print_version (void)
{
    /* output bilingual notice */
    fprintf (stderr,
	     "LibC -> ANSI-C library %s release, version %s.\n\n"
	     "Compiled by GNU-C version %s\n\n"
	     "All  source code  is written  by  Project C Library  Group,\n"
	     "and completely in public domain.  You can freely use, copy\n"
	     "modify,  and redistribute the whole contents, even without\n"
	     "this notice.\n\n"
	     "本ライブラリのために作成された全てのソースコードはＣライブ\n"
	     "ラリ作成グループの手によって新規に作成されたものであり、パ\n"
	     "ブリックドメインとして公開されています。したがって、望む人\n"
	     "は誰でも自由に使用、コピー、変更、再配布をおこなうことがで\n"
	     "き、この注意書きを添付する必要すらありません。\n",
	     _libc_release,
	     _libc_version,
	     __VERSION__);
}
