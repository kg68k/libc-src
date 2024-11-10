* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ioctrlwd.s,v 1.3 1993/10/06 17:00:56 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_ioctrlwd

		.offset		4

drive:		.ds.l		1
buffer:		.ds.l		1
size:		.ds.l		1

		.text

__dos_ioctrlwd:
		move.l		12(sp),-(sp)		* size
		move.l		12(sp),-(sp)		* buffer
		move.w		14(sp),-(sp)		* drive
		move.w		#5,-(sp)
		dc.w		__IOCTRL
		lea.l		12(sp),sp
		rts

		.end
