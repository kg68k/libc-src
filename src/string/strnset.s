* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strnset.s,v 1.1.1.1 1993/04/18 16:25:43 mura Exp $
*

		.xdef		_strnset

		.offset		4

buffer:		.ds.l		1
character:	.ds.l		1
n:		.ds.l		1

		.text

_strnset:
		movem.l		buffer(sp),d0/d1/d2
		movea.l		d0,a0
		subq.l		#1,d2
		bmi		end
set_loop:
		tst.b		(a0)
		bze		end
		move.b		d1,(a0)+
		dbra		d2,set_loop
		clr.w		d2		*-	swap.w		d2
		subq.l		#1,d2		*-	subq.w		#1,d2
		bcc		set_loop	*-	bcs		end
						*-	swap.w		d2
						*-	bra		set_loop
end:
		rts

		.end
