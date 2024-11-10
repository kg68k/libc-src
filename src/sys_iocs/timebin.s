* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: timebin.s,v 1.2 1993/10/06 17:19:36 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_timebin

		.offset		4

bcdtime		.ds.l		1

		.text

__iocs_timebin:
		move.l		bcdtime(sp),d1
		iocs		__TIMEBIN
		rts

		.end
