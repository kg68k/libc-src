* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ioctrlst.s,v 1.3 1993/10/06 17:00:52 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_ioctrlst

		.offset		4

fno:		.ds.l		1
data:		.ds.l		1

		.text

__dos_ioctrlst:
		move.w		10(sp),-(sp)		* data
		move.w		8(sp),-(sp)		* fno
		move.w		#1,-(sp)
		dc.w		__IOCTRL
		addq.w		#6,sp
		rts

		.end
