* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: lof232c.s,v 1.3 1993/10/06 17:15:27 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_lof232c

		.text

__iocs_lof232c:
		iocs		__LOF232C
		rts

		.end
