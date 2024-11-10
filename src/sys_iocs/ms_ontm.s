* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ms_ontm.s,v 1.3 1993/10/06 17:16:07 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_ms_ontm

		.offset		4

mode		.ds.l		1
maxtime		.ds.l		1

		.text

__iocs_ms_ontm:
		movem.l		mode(sp),d1-d2
		iocs		__MS_ONTM
		rts

		.end
