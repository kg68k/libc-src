* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fflush.s,v 1.3 1993/10/06 16:57:15 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fflush

		.text

__dos_fflush:
		dc.w		__FFLUSH
		rts

		.end
