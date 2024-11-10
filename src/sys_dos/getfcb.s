* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: getfcb.s,v 1.3 1993/10/06 16:58:26 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_getfcb

		.offset		4

fno:		.ds.l		1

		.text

__dos_getfcb:
		move.w		6(sp),-(sp)		* fno
		dc.w		__GETFCB
		addq.w		#2,sp
		rts

		.end
