* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fgetc.s,v 1.3 1993/10/06 16:57:19 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fgetc

		.offset		4

fno:		.ds.l		1

		.text

__dos_fgetc:
		move.w		6(sp),-(sp)		* fno
		dc.w		__FGETC
		addq.w		#2,sp
		rts

		.end
