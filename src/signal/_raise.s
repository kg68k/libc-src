* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _raise.s,v 1.1.1.1 1993/04/18 16:20:42 mura Exp $
*

		.xdef		__raise

		.offset		4*2

pcnt		.ds.l		1
sig		.ds.l		1

		.text

__raise:
		movem.l		d7/a6,-(sp)
		move.l		sig(sp),d7
		add.l		#$100,d7
		move.l		pcnt(sp),-(sp)
		clr.w		-(sp)
		movea.l		sp,a6
		trap		#14
		addq.l		#6,sp
		movem.l		(sp)+,d7/a6
		rts

		.end
