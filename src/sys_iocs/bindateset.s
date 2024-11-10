* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bindateset.s,v 1.2 1993/10/06 17:12:35 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bindateset

		.offset		4

bcddate		.ds.l		1

		.text

__iocs_bindateset:
		move.l		bcddate(sp),d1	* bcddate
		iocs		__DATESET
		rts

		.end
