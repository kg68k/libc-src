* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: hendspsc.s,v 1.3 1993/10/06 16:59:28 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_hendspsc

		.text

__dos_hendspsc:
		move.w		#11,-(sp)
		dc.w		__HENDSP
		addq.w		#2,sp
		rts

		.end
