* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: c_curon.s,v 1.3 1993/10/06 16:53:10 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_c_curon

		.text

__dos_c_curon:
		move.w		#17,-(sp)
		dc.w		__CONCTRL
		addq.w		#2,sp
		rts

		.end
