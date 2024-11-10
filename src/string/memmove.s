* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: memmove.s,v 1.1.1.1 1993/04/18 16:25:16 mura Exp $
*

		.xdef		_memmove

		.offset		4

region1:	.ds.l		1
region2:	.ds.l		1
n:		.ds.l		1

		.text

_memmove:
		movem.l		region1(sp),a0/a1/a2
		move.l		a0,d0
		move.l		a2,d1
		ble		end
		cmpa.l		a0,a1
		bpl		do_inccopy
		movea.l		a1,a2
		adda.l		d1,a2
		cmpa.l		a2,a0
		bpl		do_inccopy
		adda.l		d1,a0
		subq.l		#1,d1
dec_copy:
		move.b		-(a2),-(a0)
		dbra		d1,dec_copy
		clr.w		d1		*-	swap.w		d1
		subq.l		#1,d1		*-	subq.w		#1,d1
		bcc		dec_copy	*-	bcs		end
						*-	swap.w		d1
						*-	bra		dec_copy
.if 1						*-
		rts				*-
.else						*-
		bra		end		*-
.endif						*-

do_inccopy:
		subq.l		#1,d1
inc_copy:
		move.b		(a1)+,(a0)+
		dbra		d1,inc_copy
		clr.w		d1		*-	swap.w		d1
		subq.l		#1,d1		*-	subq.w		#1,d1
		bcc		inc_copy	*-	bcs		end
						*-	swap.w		d1
						*-	bra		inc_copy
end:
		rts

		.end
