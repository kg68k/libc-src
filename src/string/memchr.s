* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: memchr.s,v 1.1.1.1 1993/04/18 16:25:12 mura Exp $
*

		.xdef		_memchr

		.offset		4

region:		.ds.l		1
character:	.ds.l		1
n:		.ds.l		1

		.text

_memchr:
		movem.l		region(sp),d0/d1/d2
		move.l		d0,a0
		subq.l		#1,d2
		bmi		not_found
chr_loop:
		cmp.b		(a0)+,d1
		dbeq		d2,chr_loop
		beq		found
		clr.w		d2		*-	swap.w		d2
		subq.l		#1,d2		*-	subq.w		#1,d2
		bcc		chr_loop	*-	bcs		not_found
						*-	swap.w		d2
						*-	bra		chr_loop
not_found:
		moveq.l		#0,d0
		rts
found:
		subq.w		#1,a0
		move.l		a0,d0
		rts

		.end
