* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: kflushio.s,v 1.3 1993/10/06 17:01:54 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_kflushio

		.offset		4

code:		.ds.l		1

		.text

__dos_kflushio:
		move.w		6(sp),-(sp)		* code
		move.w		#$06,-(sp)
		dc.w		__KFLUSH
		addq.w		#4,sp
		rts

		.end
