* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fputc.s,v 1.3 1993/10/06 16:57:46 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fputc

		.offset		4

code:		.ds.l		1
fno:		.ds.l		1

		.text

__dos_fputc:
		move.w		10(sp),-(sp)		* fno
		move.w		8(sp),-(sp)		* code
		dc.w		__FPUTC
		addq.w		#4,sp
		rts

		.end
