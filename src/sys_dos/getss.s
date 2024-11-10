* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: getss.s,v 1.3 1993/10/06 16:58:39 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_getss

		.offset		4

inpptr:		.ds.l		1

		.text

__dos_getss:
		move.l		4(sp),-(sp)		* inpptr
		dc.w		__GETSS
		addq.w		#4,sp
		rts

		.end
