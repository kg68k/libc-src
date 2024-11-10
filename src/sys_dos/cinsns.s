* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: cinsns.s,v 1.4 1993/10/06 16:54:46 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_cinsns

		.text

__dos_cinsns:
		dc.w		__CINSNS
		rts

		.end
