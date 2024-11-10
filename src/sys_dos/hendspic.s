* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: hendspic.s,v 1.3 1993/10/06 16:58:52 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_hendspic

		.offset		4

pos:		.ds.l		1

		.text

__dos_hendspic:
		move.w		6(sp),-(sp)		* pos
		move.w		#7,-(sp)
		dc.w		__HENDSP
		addq.w		#4,sp
		rts

		.end
