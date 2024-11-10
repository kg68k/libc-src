* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: setdate.s,v 1.3 1993/10/06 17:04:40 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_setdate

		.offset		4

date:		.ds.l		1

		.text

__dos_setdate:
		move.w		6(sp),-(sp)		* date
		dc.w		__SETDATE
		addq.w		#2,sp
		rts

		.end
