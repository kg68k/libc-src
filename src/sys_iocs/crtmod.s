* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: crtmod.s,v 1.2 1993/10/06 17:13:10 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_crtmod

		.offset		4

mode		.ds.l		1

		.text

__iocs_crtmod:
		move.l		mode(sp),d1	* crt mode
		iocs		__CRTMOD
		rts

		.end
