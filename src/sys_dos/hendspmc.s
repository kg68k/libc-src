* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: hendspmc.s,v 1.3 1993/10/06 16:59:10 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_hendspmc

		.text

__dos_hendspmc:
		move.w		#3,-(sp)
		dc.w		__HENDSP
		addq.w		#2,sp
		rts

		.end
