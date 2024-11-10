* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: seek.s,v 1.3 1993/10/06 17:04:26 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_seek

		.offset		4

fno:		.ds.l		1
offset:		.ds.l		1
mode:		.ds.l		1

		.text

__dos_seek:
		move.w		14(sp),-(sp)		* mode
		move.l		10(sp),-(sp)		* offset
		move.w		12(sp),-(sp)		* fno
		dc.w		__SEEK
		addq.w		#8,sp
		rts

		.end
