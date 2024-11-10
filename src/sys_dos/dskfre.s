* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dskfre.s,v 1.3 1993/10/06 16:56:26 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_dskfre

		.offset		4

drive:		.ds.l		1
buffer:		.ds.l		1

		.text

__dos_dskfre:
		move.l		8(sp),-(sp)		* buffer
		move.w		10(sp),-(sp)		* drive
		dc.w		__DSKFRE
		addq.w		#6,sp
		rts

		.end
