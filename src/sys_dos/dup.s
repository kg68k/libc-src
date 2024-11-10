* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dup.s,v 1.3 1993/10/06 16:56:31 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_dup

		.offset		4

fno:		.ds.l		1

		.text

__dos_dup:
		move.w		6(sp),-(sp)		* fno
		dc.w		__DUP
		addq.w		#2,sp
		rts

		.end
