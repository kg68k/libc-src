* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strcat.s,v 1.1.1.1 1993/04/18 16:25:21 mura Exp $
*

		.xdef		_strcat

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_strcat:
		movem.l		string1(sp),a0/a1
		move.l		a0,d0
skip_loop:
		tst.b		(a0)+
		bne		skip_loop
		subq.w		#1,a0
cpy_loop:
		move.b		(a1)+,(a0)+
		bne		cpy_loop
		rts

		.end
