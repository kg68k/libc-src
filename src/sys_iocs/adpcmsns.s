* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: adpcmsns.s,v 1.2 1993/10/06 17:07:19 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_adpcmsns

		.text

__iocs_adpcmsns:
		iocs		__ADPCMSNS
		rts

		.end
