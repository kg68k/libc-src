* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: rassign.s,v 1.3 1993/10/06 17:03:50 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_rassign

		.offset		4

path1:		.ds.l		1

		.text

__dos_rassign:
		move.l		4(sp),-(sp)		* path1
		move.w		#4,-(sp)
		dc.w		__ASSIGN
		addq.w		#6,sp
		rts

		.end
