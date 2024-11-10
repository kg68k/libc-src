* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: filedate.s,v 1.3 1993/10/06 16:57:28 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_filedate

		.offset		4

fno:		.ds.l		1
datetime:		.ds.l		1

		.text

__dos_filedate:
		move.l		8(sp),-(sp)		* datetime
		move.w		10(sp),-(sp)		* fno
		dc.w		__FILEDATE
		addq.w		#6,sp
		rts

		.end
