* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: setpdb.s,v 1.3 1993/10/06 17:04:49 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_setpdb

		.offset		4

pdbadr:		.ds.l		1

		.text

__dos_setpdb:
		move.l		4(sp),-(sp)		* pdbadr
		dc.w		__SETPDB
		addq.w		#4,sp
		rts

		.end
