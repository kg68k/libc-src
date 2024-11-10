* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ioctrlis.s,v 1.3 1993/10/06 17:00:30 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_ioctrlis

		.offset		4

fno:		.ds.l		1

		.text

__dos_ioctrlis:
		move.w		6(sp),-(sp)		* fno
		move.w		#6,-(sp)
		dc.w		__IOCTRL
		addq.w		#4,sp
		rts

		.end
