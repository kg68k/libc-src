* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: contrast.s,v 1.2 1993/10/06 17:12:59 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_contrast

		.offset		4

mode		.ds.l		1

		.text

__iocs_contrast:
		move.l		mode(sp),d1
		iocs		__CONTRAST
		rts

		.end
