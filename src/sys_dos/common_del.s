* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: common_del.s,v 1.3 1993/10/06 16:55:03 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_common_del

		.offset		4

name:		.ds.l		1

		.text

__dos_common_del:
		move.l		4(sp),-(sp)		* name
		move.w		#5,-(sp)
		dc.w		__COMMON
		addq.w		#6,sp
		rts

		.end
