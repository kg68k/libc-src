* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: chgdrv.s,v 1.3 1993/10/06 16:54:37 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_chgdrv

		.offset		4

drv:		.ds.l		1

		.text

__dos_chgdrv:
		move.w		6(sp),-(sp)		* drv
		dc.w		__CHGDRV
		addq.w		#2,sp
		rts

		.end
