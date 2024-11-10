* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* based on the contribution by TomY.
* --------------------------------------------------------------------
* $Id: swmem.s,v 1.2 1993/09/07 16:22:18 mura Exp $
*

		.xdef		_swmem

		.offset		4

ptr1:		.ds.l		1
ptr2:		.ds.l		1
size:		.ds.l		1

		.text

_swmem:
		movem.l		ptr1(sp),a0-a1
		move.l		size(sp),d0
		beq		end
loop:
		move.b		(a0),d1
		move.b		(a1),(a0)+
		move.b		d1,(a1)+
		subq.l		#1,d0
		bne		loop
end:
		rts

		.end
