* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: chdir.s,v 1.3 1993/10/06 16:54:33 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_chdir

		.offset		4

file:		.ds.l		1

		.text

__dos_chdir:
		move.l		4(sp),-(sp)		* file
		dc.w		__CHDIR
		addq.w		#4,sp
		rts

		.end
