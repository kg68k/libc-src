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
* $Id: repmem.s,v 1.2 1993/09/07 16:21:33 mura Exp $
*

		.xdef		_repmem

		.offset		4

buffer:		.ds.l		1
source:		.ds.l		1
size:		.ds.l		1
num:		.ds.l		1

		.text

_repmem:
		movem.l		buffer(sp),a0-a2
		move.l		num(sp),d2
		beq		end
		move.l		a2,d1
		beq		end
nloop:
		movea.l		a1,a2
		move.l		d1,d0
cloop:
		move.b		(a2)+,(a0)+
		subq.l		#1,d0
		bne		cloop
		subq.l		#1,d2
		bne		nloop
end:
		rts

		.end
