* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ms_patst.s,v 1.3 1993/10/06 17:16:12 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_ms_patst

		.offset		4

no		.ds.l		1
addr		.ds.l		1

		.text

__iocs_ms_patst:
		movem.l		no(sp),d1/a1
		iocs		__MS_PATST
		rts

		.end
