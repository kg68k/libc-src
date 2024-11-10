* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: loadonly.s,v 1.3 1993/10/06 17:02:12 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_loadonly

		.offset		4

file:		.ds.l		1
loadadr:	.ds.l		1
limitadr:	.ds.l		1

		.text

__dos_loadonly:
		move.l		12(sp),-(sp)		* limitadr
		move.l		12(sp),-(sp)		* loadadr
		move.l		12(sp),-(sp)		* file
		move.w		#3,-(sp)
		dc.w		__EXEC
		lea.l		14(sp),sp
		rts

		.end
