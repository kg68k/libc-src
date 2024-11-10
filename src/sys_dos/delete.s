* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: delete.s,v 1.3 1993/10/06 16:55:56 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_delete

		.offset		4

file:		.ds.l		1

		.text

__dos_delete:
		move.l		4(sp),-(sp)		* file
		dc.w		__DELETE
		addq.w		#4,sp
		rts

		.end
