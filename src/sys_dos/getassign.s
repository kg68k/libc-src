* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: getassign.s,v 1.3 1993/10/06 16:57:59 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_getassign

		.offset		4

path1:		.ds.l		1
path2:		.ds.l		1

		.text

__dos_getassign:
		move.l		8(sp),-(sp)		* path2
		move.l		8(sp),-(sp)		* path1
		clr.w		-(sp)
		dc.w		__ASSIGN
		lea.l		10(sp),sp
		rts

		.end
