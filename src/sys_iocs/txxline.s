* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: txxline.s,v 1.3 1993/10/06 17:20:36 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_txxline

		.offset		4

addr		.ds.l		1

		.text

__iocs_txxline:
		movea.l		addr(sp),a1
		iocs		__TXXLINE
		rts

		.end
