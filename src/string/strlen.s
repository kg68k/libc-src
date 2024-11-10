* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strlen.s,v 1.1.1.1 1993/04/18 16:25:35 mura Exp $
*

		.xdef		_strlen

		.offset		4

string:		.ds.l		1

		.text
_strlen:
		movea.l		string(sp),a0
		moveq.l		#1,d1
		add.l		a0,d1
len_loop:
		tst.b		(a0)+
		bnz		len_loop
		move.l		a0,d0
		sub.l		d1,d0
		rts

		.end
