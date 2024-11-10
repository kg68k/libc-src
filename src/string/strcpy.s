* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strcpy.s,v 1.1.1.1 1993/04/18 16:25:27 mura Exp $
*

		.xdef		_strcpy

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_strcpy:
		movem.l		string1(sp),a0/a1
		move.l		a0,d0
cpy_loop:
		move.b		(a1)+,(a0)+
		bnz		cpy_loop
		rts

		.end
