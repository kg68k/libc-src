* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: s_malloc.s,v 1.4 1993/10/06 17:04:13 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_s_malloc

		.offset		4

md:		.ds.l		1
size:		.ds.l		1

		.text

__dos_s_malloc:
		move.l		8(sp),-(sp)		* size
		move.w		10(sp),-(sp)		* md
		dc.w		__S_MALLOC
		addq.w		#6,sp
		rts

		.end
