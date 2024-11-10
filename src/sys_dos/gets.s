* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: gets.s,v 1.4 1993/10/06 16:58:35 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_gets

		.offset		4

ptr:		.ds.l		1

		.text

__dos_gets:
		move.l		4(sp),-(sp)		* ptr
		dc.w		__GETS
		addq.w		#4,sp
		rts

		.end
