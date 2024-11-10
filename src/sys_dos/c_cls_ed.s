* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: c_cls_ed.s,v 1.3 1993/10/06 16:52:53 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_c_cls_ed

		.text

__dos_c_cls_ed:
		clr.w		-(sp)
		move.w		#10,-(sp)
		dc.w		__CONCTRL
		addq.w		#4,sp
		rts

		.end
