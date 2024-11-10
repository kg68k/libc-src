* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dayasc.s,v 1.2 1993/10/06 17:13:35 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_dayasc

		.offset		4

binday		.ds.l		1
addr		.ds.l		1

		.text

__iocs_dayasc:
		movem.l		binday(sp),d1/a1
		iocs		__DAYASC
		rts

		.end
