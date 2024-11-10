* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcsspn.s,v 1.1.1.1 1993/04/18 16:42:11 mura Exp $
*

		.xdef		_wcsspn

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_wcsspn:
		movem.l		string1(sp),a0/a1
		move.l		a1,a2
len_loop:
		tst.l		(a2)+
		bne		len_loop
		move.l		a2,d1
		sub.l		a1,d1
		asr.l		#2,d1
		subq.l		#2,d1
		bmi		whole
big_loop:
		move.l		(a0)+,d0
		movea.l		a1,a2
		move.l		d1,d2
little_loop:
		cmp.l		(a2)+,d0
		dbze		d2,little_loop
		bze		big_loop
		clr.w		d2
		subq.l		#1,d2
		bcc		little_loop
break_out:
		move.l		a0,d0
		sub.l		string1(sp),d0
		subq.l		#1,d0
		rts
whole:
		moveq.l		#1,d0
		add.l		d1,d0
		rts

		.end
