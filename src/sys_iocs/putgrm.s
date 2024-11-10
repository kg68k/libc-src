* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: putgrm.s,v 1.3 1993/10/06 17:17:36 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_putgrm

		.offset		4

ptr		.ds.l		1

		.text

__iocs_putgrm:
		movea.l		ptr(sp),a1
		iocs		__PUTGRM
		rts

		.end
