* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ioctrlrtset.s,v 1.3 1993/10/06 17:00:48 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_ioctrlrtset

		.offset		4

count:		.ds.l		1
time:		.ds.l		1

		.text

__dos_ioctrlrtset:
		move.w		10(sp),-(sp)		* time
		move.w		8(sp),-(sp)		* count
		move.w		#11,-(sp)
		dc.w		__IOCTRL
		addq.w		#6,sp
		rts

		.end
