* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: timeset.s,v 1.2 1993/10/06 17:19:57 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_timeset

		.offset		4

bcdtime		.ds.l		1

		.text

__iocs_timeset:
		move.l		bcdtime(sp),d1	* bcdtime
		iocs		__TIMESET
		rts

		.end
