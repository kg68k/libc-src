* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bzero.s,v 1.1.1.1 1993/04/18 16:25:06 mura Exp $
*

		.xdef		_bzero

		.offset		4

buffer:		.ds.l		1
n:		.ds.l		1

		.text

_bzero:
		movea.l		buffer(sp),a0
		moveq.l		#0,d1
		move.l		n(sp),d2
		subq.l		#1,d2
		bmi		end
set_loop:
		move.b		d1,(a0)+
		dbra		d2,set_loop
		clr.w		d2		*-	swap.w		d2
		subq.l		#1,d2		*-	subq.w		#1,d2
		bcc		set_loop	*-	bcs		end
						*-	swap.w		d2
						*-	bra		set_loop
end:
		moveq.l		#0,d0
		rts

		.end
