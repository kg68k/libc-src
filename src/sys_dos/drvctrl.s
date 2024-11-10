* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: drvctrl.s,v 1.3 1993/10/06 16:56:17 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_drvctrl

		.offset		4

mode:		.ds.l		1
drv:		.ds.l		1

		.text

__dos_drvctrl:
		move.w		6(sp),d0
		lsl.w		#8,d0
		move.b		11(sp),d0
		move.w		d0,-(sp)
		dc.w		__DRVCTRL
		addq.w		#2,sp
		rts

		.end
