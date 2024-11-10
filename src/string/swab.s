* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: swab.s,v 1.1.1.1 1993/04/18 16:26:02 mura Exp $
*

		.xdef		_swab

		.offset		4

src:		.ds.l		1
dist:		.ds.l		1
nbytes:		.ds.l		1

		.text

_swab:
		movem.l		src(sp),a0-a2
		move.l		a2,d0
		lsr.l		#1,d0
		beq		end
		subq.l		#1,d0
loop:
		move.b		(a0)+,d1
		move.b		(a0)+,(a1)+
		move.b		d1,(a1)+
		dbra		d0,loop
		clr.w		d0
		subq.l		#1,d0
		bcc		loop
end:
		rts

		.end
