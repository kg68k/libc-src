* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: hendspmr.s,v 1.3 1993/10/06 16:59:24 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_hendspmr

		.offset		4

pos:		.ds.l		1
mesptr:		.ds.l		1

		.text

__dos_hendspmr:
		move.l		8(sp),-(sp)		* mesptr
		move.w		10(sp),-(sp)		* pos
		move.w		#2,-(sp)
		dc.w		__HENDSP
		addq.w		#8,sp
		rts

		.end
