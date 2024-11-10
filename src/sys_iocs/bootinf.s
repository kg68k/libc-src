* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bootinf.s,v 1.3 1993/10/06 17:12:40 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bootinf

		.text

__iocs_bootinf:
		iocs		__BOOTINF
		rts

		.end
