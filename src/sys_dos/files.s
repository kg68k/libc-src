* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: files.s,v 1.3 1993/10/06 16:57:32 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_files

		.offset		4

buffer:		.ds.l		1
file:		.ds.l		1
attr:		.ds.l		1

		.text

__dos_files:
		move.w		14(sp),-(sp)		* attr
		move.l		10(sp),-(sp)		* file
		move.l		10(sp),-(sp)		* buffer
		dc.w		__FILES
		lea.l		10(sp),sp
		rts

		.end
