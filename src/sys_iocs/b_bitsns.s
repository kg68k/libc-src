* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_bitsns.s,v 1.2 1993/10/06 17:07:57 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bitsns

		.offset		4

group		.ds.l		1

		.text

__iocs_bitsns:
		move.l		group(sp),d1	* key group
		iocs		__BITSNS
		rts

		.end
