* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: breakck.s,v 1.3 1993/10/06 16:52:44 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_breakck

		.offset		4

flag:		.ds.l		1

		.text

__dos_breakck:
		move.w		6(sp),-(sp)		* flag
		dc.w		__BREAKCK
		addq.w		#2,sp
		rts

		.end
