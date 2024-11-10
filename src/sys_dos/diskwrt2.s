* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: diskwrt2.s,v 1.4 1993/10/06 16:56:13 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_diskwrt2

		.offset		4

addr:		.ds.l		1
drive:		.ds.l		1
sector:		.ds.l		1
seclen:		.ds.l		1

		.text

__dos_diskwrt2:
		move.l		16(sp),-(sp)		* seclen
		move.l		16(sp),-(sp)		* sector
		move.w		18(sp),-(sp)		* drive
		move.l		14(sp),d0
		bset.l		#31,d0
		move.l		d0,-(sp)		* addr
		dc.w		__DISKWRT
		lea.l		14(sp),sp
		rts

		.end
