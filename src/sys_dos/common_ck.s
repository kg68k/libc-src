* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: common_ck.s,v 1.3 1993/10/06 16:54:59 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_common_ck

		.offset		4

name:		.ds.l		1

		.text

__dos_common_ck:
		move.l		4(sp),-(sp)		* name
		clr.w		-(sp)
		dc.w		__COMMON
		addq.w		#6,sp
		rts

		.end
