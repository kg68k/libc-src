* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: diskred.s,v 1.3 1993/10/06 16:56:00 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_diskred

		.offset		4

addr:		.ds.l		1
drive:		.ds.l		1
sector:		.ds.l		1
seclen:		.ds.l		1

		.text

__dos_diskred:
		move.w		18(sp),-(sp)		* seclen
		move.w		16(sp),-(sp)		* sector
		move.w		14(sp),-(sp)		* drive
		move.l		10(sp),-(sp)		* addr
		dc.w		__DISKRED
		lea.l		10(sp),sp
		rts

		.end
