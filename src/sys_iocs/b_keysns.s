* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_keysns.s,v 1.2 1993/10/06 17:09:56 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_keysns

		.text

__iocs_b_keysns:
		iocs		__B_KEYSNS
		rts

		.end
