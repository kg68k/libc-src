* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_sftsns.s,v 1.2 1993/10/06 17:11:16 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_sftsns

		.text

__iocs_b_sftsns:
		iocs		__B_SFTSNS
		rts

		.end
