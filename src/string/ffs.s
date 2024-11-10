* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ffs.s,v 1.1.1.1 1993/04/18 16:25:08 mura Exp $
*

		.xdef		_ffs

		.offset		4

mask:		.ds.l		1

		.text

_ffs:
		move.l		mask(sp),d1
		beq		errout
		moveq.l		#0,d0
		btst.l		d0,d1
		bne		end
loop:
		addq.l		#1,d0
		btst.l		d0,d1
		beq		loop
end:
		addq.l		#1,d0
		rts
errout:
		moveq.l		#0,d0
		rts

		.end
