* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: cominp.s,v 1.3 1993/10/06 16:54:55 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_cominp

		.text

__dos_cominp:
		dc.w		__COMINP
		rts

		.end
