* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: memcpy.s,v 1.1.1.1 1993/04/18 16:25:15 mura Exp $
*

		.xdef		_memcpy

		.offset		4

region1:	.ds.l		1
region2:	.ds.l		1
n:		.ds.l		1

		.text

_memcpy:
		movem.l		region1(sp),a0/a1
		move.l		a0,d0
		move.l		n(sp),d1
		ble		end
		subq.l		#1,d1
cpy_loop:
		move.b		(a1)+,(a0)+
		dbra		d1,cpy_loop
		clr.w		d1		*-	swap.w		d1
		subq.l		#1,d1		*-	subq.w		#1,d1
		bcc		cpy_loop	*-	bcs		end
						*-	swap.w		d1
						*-	bra		cpy_loop
end:
		rts

		.end
