* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bgctrlgt.s,v 1.3 1993/10/06 17:11:53 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bgctrlgt

		.offset		4

mode		.ds.l		1

		.text

__iocs_bgctrlgt:
		move.l		mode(sp),d1
		iocs		__BGCTRLGT
		rts

		.end
