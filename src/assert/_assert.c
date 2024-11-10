/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: _assert.c,v 1.4 1994/07/27 13:46:19 mura Exp $
 */

/* System headers */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Functions */
void _assert (const char *expression, int lineno, const char *fname)
{
#ifdef __LIBSXC__

    register int reg_d0 asm ("d0");
    char buf[256];

    /* sprintf はまだ動かない:-P */
    sprintf (buf, "Assertion failed:\n<%s>\nat line %u, in file %s\n",
	     expression, lineno, fname);

    /* DMError */
    asm volatile ("move.l %1,-(sp)\n\t"
		  "move.w #$8007,-(sp)\n\t"
		  "dc.w $a2f6\n\t"
		  "addq.w #6,sp"
		    : "=r" (reg_d0)
		    : "g" (&buf)
		    : "a0");

    /* "中断" を押すと abort、"継続" なら return */
    if (reg_d0 != 1)
	abort ();

#else

    /* 表示 */
    fputs ("Assertion failed: <", stderr);

    /* expression 部分を stderr に fputc する */
    fputs (expression, stderr);

    /* 行、ファイル名を表示 */
    fprintf (stderr, "> at line %d, in file %s\n", lineno, fname);

    /* アボート */
    abort ();

#endif
}
