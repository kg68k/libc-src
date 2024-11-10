* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcscpy.s,v 1.1.1.1 1993/04/18 16:41:57 mura Exp $
*

		.xdef		_wcscpy

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_wcscpy:
		movem.l		string1(sp),a0/a1
		move.l		a0,d0
cpy_loop:
		move.l		(a1)+,(a0)+
		bnz		cpy_loop
		rts

		.end
