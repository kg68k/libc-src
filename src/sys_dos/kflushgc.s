* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: kflushgc.s,v 1.3 1993/10/06 17:01:37 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_kflushgc

		.text

__dos_kflushgc:
		move.w		#$08,-(sp)
		dc.w		__KFLUSH
		addq.w		#2,sp
		rts

		.end
