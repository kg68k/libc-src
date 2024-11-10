* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ms_sel.s,v 1.3 1993/10/06 17:16:16 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_ms_sel

		.offset		4

no		.ds.l		1

		.text

__iocs_ms_sel:
		move.l		no(sp),d1
		iocs		__MS_SEL
		rts

		.end
