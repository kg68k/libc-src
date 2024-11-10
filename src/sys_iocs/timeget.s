* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: timeget.s,v 1.2 1993/10/06 17:19:47 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_timeget

		.text

__iocs_timeget:
		iocs		__TIMEGET
		rts

		.end
