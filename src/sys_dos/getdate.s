* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: getdate.s,v 1.3 1993/10/06 16:58:13 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_getdate

		.text

__dos_getdate:
		dc.w		__GETDATE
		rts

		.end
