* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: stpcpy.s,v 1.1 1993/11/13 06:35:29 mura Exp $
*

		.xdef		_stpcpy

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_stpcpy:
		movem.l		string1(sp),a0/a1
cpy_loop:
		move.b		(a1)+,(a0)+
		bnz		cpy_loop
		move.l		a0,d0
		subq.l		#1,d0
		rts

		.end
