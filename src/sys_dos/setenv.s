* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: setenv.s,v 1.3 1993/10/06 17:04:44 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_setenv

		.offset		4

name:		.ds.l		1
env:		.ds.l		1
buffer:		.ds.l		1

		.text

__dos_setenv:
		move.l		12(sp),-(sp)		* buffer
		move.l		12(sp),-(sp)		* env
		move.l		12(sp),-(sp)		* name
		dc.w		__SETENV
		lea.l		12(sp),sp
		rts

		.end
