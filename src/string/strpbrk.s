* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strpbrk.s,v 1.1.1.1 1993/04/18 16:25:44 mura Exp $
*

		.xdef		_strpbrk

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_strpbrk:
		movem.l		string1(sp),a0/a1
		move.l		a1,a2
len_loop:
		tst.b		(a2)+
		bne		len_loop
		move.l		a2,d1
		sub.l		a1,d1
		subq.l		#2,d1
		bmi		not_found
big_loop:
		move.b		(a0)+,d0
		bze		not_found	*
		movea.l		a1,a2
		move.l		d1,d2
little_loop:
		cmp.b		(a2)+,d0
		dbeq		d2,little_loop
		beq		end
		clr.w		d2		*-	swap.w		d2
		subq.l		#1,d2		*-	subq.w		#1,d2
		bcc		little_loop	*-	bcs		big_loop
		bra		big_loop	*-	swap.w		d2
						*-	bra		little_loop
end:
		subq.w		#1,a0
		move.l		a0,d0
		rts
not_found:
		moveq.l		#0,d0
		rts

		.end
