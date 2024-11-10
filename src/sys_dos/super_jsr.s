* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: super_jsr.s,v 1.3 1993/10/06 17:05:11 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_super_jsr

		.offset		4

func:		.ds.l		1
inregs:		.ds.l		1
outregs:	.ds.l		1

		.text

__dos_super_jsr:
		movem.l		d0-d7/a0-a6,-(sp)
		move.l		72(sp),-(sp)		* outregs
		move.l		68(sp),-(sp)		* func
		move.l		76(sp),a0		* inregs
		movem.l		(a0),d0-d7/a0-a6
		dc.w		__SUPER_JSR
		move.l		a6,-(sp)
		move.l		8(sp),a6
		move.l		(sp)+,56(a6)
		addq.w		#8,sp
		movem.l		d0-d7/a0-a5,(a6)
		movem.l		(sp)+,d0-d7/a0-a6
		rts

		.end
