* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: memcpy.s,v 1.3 1993/10/06 17:02:39 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_memcpy

		.offset		4

s_adr:		.ds.l		1
d_adr:		.ds.l		1
mode:		.ds.l		1

		.text

__dos_memcpy:
		move.w		14(sp),-(sp)		* size
		move.l		10(sp),-(sp)		* d_adr
		move.l		10(sp),-(sp)		* s_adr
		dc.w		__MEMCPY
		lea.l		10(sp),sp
		rts

		.end
