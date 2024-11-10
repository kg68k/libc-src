* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bindatebcd.s,v 1.2 1993/10/06 17:12:25 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bindatebcd

		.offset		4

bindate		.ds.l		1

		.text

__iocs_bindatebcd:
		move.l		bindate(sp),d1	* bindate
		iocs		__DATEBCD
		rts

		.end
