* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: adpcmmod.s,v 1.2 1993/10/06 17:07:09 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_adpcmmod

		.offset		4

mode		.ds.l		1

		.text

__iocs_adpcmmod:
		move.l		mode(sp),d1
		iocs		__ADPCMMOD
		rts

		.end
