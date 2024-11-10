* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: curdrv.s,v 1.3 1993/10/06 16:55:51 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_curdrv

		.text

__dos_curdrv:
		dc.w		__CURDRV
		rts

		.end
