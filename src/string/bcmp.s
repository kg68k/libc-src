* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bcmp.s,v 1.1.1.1 1993/04/18 16:25:03 mura Exp $
*

		.xdef		_bcmp

		.offset		4

region1:	.ds.l		1
region2:	.ds.l		1
count:		.ds.l		1

		.text

_bcmp:
		movem.l		region1(sp),a0/a1/a2
		move.l		a2,d1
		ble		end
		subq.l		#1,d1
cmp_loop:
		cmp.b		(a1)+,(a0)+
		dbne		d1,cmp_loop
		bne		differ
		clr.w		d1		*-	swap.w		d1
		subq.l		#1,d1		*-	subq.w		#1,d1
		bcc		cmp_loop	*-	bcs		end
						*-	swap.w		d1
						*-	bra		cmp_loop
end:
		moveq.l		#0,d0
		rts
differ:
		move.b		-(a1),d0
		sub.b		-(a0),d0
		ext.w		d0
		ext.l		d0
		rts

		.end
