* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: hendspio.s,v 1.3 1993/10/06 16:58:57 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_hendspio

		.text

__dos_hendspio:
		move.w		#4,-(sp)
		dc.w		__HENDSP
		addq.w		#2,sp
		rts

		.end
