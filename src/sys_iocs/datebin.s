* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: datebin.s,v 1.2 1993/10/06 17:13:24 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_datebin

		.offset		4

bcddate		.ds.l		1

		.text

__iocs_datebin:
		move.l		bcddate(sp),d1
		iocs		__DATEBIN
		rts

		.end
