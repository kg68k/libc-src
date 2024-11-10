* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bgtextcl.s,v 1.3 1993/10/06 17:12:11 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bgtextcl

		.offset		4

page		.ds.l		1
code		.ds.l		1

		.text

__iocs_bgtextcl:
		movem.l		page(sp),d1-d2
		iocs		__BGTEXTCL
		rts

		.end
