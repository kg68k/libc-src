* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: memccpy.s,v 1.1.1.1 1993/04/18 16:25:10 mura Exp $
*

		.xdef		_memccpy

		.offset		4

region1:	.ds.l		1
region2:	.ds.l		1
c:		.ds.l		1
n:		.ds.l		1

		.text

_memccpy:
		movem.l		region1(sp),a0/a1
		move.l		c(sp),d1
		move.l		n(sp),d2
		subq.l		#1,d2
		bmi		not_end
cpy_loop:
		move.b		(a1)+,d0
		move.b		d0,(a0)+
		cmp.b		d1,d0
		dbeq		d2,cpy_loop	*-	beq		found
		beq		found_end
		clr.w		d2		*-	swap.w		d2
		subq.l		#1,d2		*-	subq.w		#1,d2
		bcc		cpy_loop	*-	bcs		end
						*-	swap.w		d2
						*-	bra		cpy_loop
not_end:
		moveq.l		#0,d0
		rts
found_end:
		move.l		a0,d0
		rts

		.end
