* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strcspn.s,v 1.1.1.1 1993/04/18 16:25:29 mura Exp $
*

		.xdef		_strcspn

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text
_strcspn:
		movem.l		string1(sp),a0/a1
		move.l		a1,a2
len_loop:
		tst.b		(a2)+
		bnz		len_loop
		move.l		a2,d1
		sub.l		a1,d1
		subq.l		#2,d1
		bmi		whole
big_loop:
		move.b		(a0)+,d0
		bze		break_out
		movea.l		a1,a2
		move.l		d1,d2
little_loop:
		cmp.b		(a2)+,d0
		dbze		d2,little_loop
		bze		break_out
		clr.w		d2		*-	swap.w		d2
		subq.l		#1,d2		*-	subq.w		#1,d2
		bcc		little_loop	*-	bcs		big_loop
		bra		big_loop	*-	swap.w		d2
						*-	bra		little_loop
break_out:
		move.l		a0,d0
		sub.l		string1(sp),d0
		subq.l		#1,d0
		rts
whole:
		moveq.l		#1,d1
		add.l		a0,d1
s1_loop:
		tst.b		(a0)+
		bnz		s1_loop
		move.l		a0,d0
		sub.l		d1,d0
		rts

		.end
