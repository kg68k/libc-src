* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strstr.s,v 1.1.1.1 1993/04/18 16:25:54 mura Exp $
*

		.xdef		_strstr

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		text

_strstr:
		movem.l		string1(sp),a0/a1
		move.l		a3,-(sp)
		move.b		(a1)+,d1
		bze		zerow
big_loop:
		move.b		(a0)+,d0
		beq		not_found
		cmp.b		d1,d0
		bne		big_loop
		move.l		a0,a2
		move.l		a1,a3
		move.b		(a3)+,d2
		beq		found
little_loop:
		cmp.b		(a2)+,d2
		bne		big_loop
		move.b		(a3)+,d2
		bne		little_loop
found:
		subq.w		#1,a0
zerow:
		move.l		a0,d0
		move.l		(sp)+,a3
		rts
not_found:
		moveq.l		#0,d0
		move.l		(sp)+,a3
		rts

		.end
