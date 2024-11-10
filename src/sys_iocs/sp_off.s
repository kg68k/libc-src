* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sp_off.s,v 1.3 1993/10/06 17:18:36 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_sp_off

		.text

__iocs_sp_off:
		iocs		__SP_OFF
		rts

		.end
