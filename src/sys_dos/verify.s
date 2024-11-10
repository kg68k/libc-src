* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: verify.s,v 1.3 1993/10/06 17:05:29 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_verify

		.offset		4

flag:		.ds.l		1

		.text

__dos_verify:
		move.w		6(sp),-(sp)		* flag
		dc.w		__VERIFY
		addq.w		#2,sp
		rts

		.end
