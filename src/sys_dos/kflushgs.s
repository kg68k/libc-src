* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: kflushgs.s,v 1.3 1993/10/06 17:01:45 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_kflushgs

		.offset		4

ptr:		.ds.l		1

		.text

__dos_kflushgs:
		move.l		4(sp),-(sp)		* ptr
		move.w		#$0a,-(sp)
		dc.w		__KFLUSH
		addq.w		#6,sp
		rts

		.end
