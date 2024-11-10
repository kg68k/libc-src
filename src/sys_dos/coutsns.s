* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: coutsns.s,v 1.2 1993/10/06 16:55:34 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_coutsns

		.text

__dos_coutsns:
		dc.w		__COUTSNS
		rts

		.end
