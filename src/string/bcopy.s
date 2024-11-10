* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bcopy.s,v 1.1.1.1 1993/04/18 16:25:05 mura Exp $
*

		.xdef		_bcopy

		.offset		4

region1:	.ds.l		1
region2:	.ds.l		1
n:		.ds.l		1

		.text

_bcopy:
		movem.l		region1(sp),a0/a1
		move.l		n(sp),d1
		ble		end
		subq.l		#1,d1
cpy_loop:
		move.b		(a0)+,(a1)+
		dbra		d1,cpy_loop
		clr.w		d1		*-	swap.w		d1
		subq.l		#1,d1		*-	subq.w		#1,d1
		bcc		cpy_loop	*-	bcs		end
						*-	swap.w		d1
						*-	bra		cpy_loop
end:
		moveq.l		#0,d0
		rts

		.end
