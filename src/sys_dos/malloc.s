* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: malloc.s,v 1.3 1993/10/06 17:02:30 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_malloc

		.offset		4

size:		.ds.l		1

		.text

__dos_malloc:
		move.l		4(sp),-(sp)		* size
		dc.w		__MALLOC
		addq.w		#4,sp
		rts

		.end
