* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: inp232c.s,v 1.3 1993/10/06 17:14:55 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_inp232c

		.text

__iocs_inp232c:
		iocs		__INP232C
		rts

		.end
