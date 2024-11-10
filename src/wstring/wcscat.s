* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcscat.s,v 1.1.1.1 1993/04/18 16:41:52 mura Exp $
*

		.xdef		_wcscat

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_wcscat:
		movem.l		string1(sp),a0/a1
		move.l		a0,d0
skip_loop:
		tst.l		(a0)+
		bne		skip_loop
		subq.w		#4,a0
cpy_loop:
		move.l		(a1)+,(a0)+
		bne		cpy_loop
		rts

		.end
