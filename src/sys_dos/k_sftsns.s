* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: k_sftsns.s,v 1.3 1993/10/06 17:01:23 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_k_sftsns

		.text

__dos_k_sftsns:
		move.w		#2,-(sp)
		dc.w		__KEYCTRL
		addq.w		#2,sp
		rts

		.end
