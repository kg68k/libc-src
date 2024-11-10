* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ioctrlrh.s,v 1.3 1993/10/06 17:00:43 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_ioctrlrh

		.offset		4

fno:		.ds.l		1
buffer:		.ds.l		1
size:		.ds.l		1

		.text

__dos_ioctrlrh:
		move.l		12(sp),-(sp)		* size
		move.l		12(sp),-(sp)		* buffer
		move.w		14(sp),-(sp)		* fno
		move.w		#2,-(sp)
		dc.w		__IOCTRL
		lea.l		12(sp),sp
		rts

		.end
