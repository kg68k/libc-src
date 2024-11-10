* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sp_init.s,v 1.3 1993/10/06 17:18:31 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_sp_init

		.text

__iocs_sp_init:
		iocs		__SP_INIT
		rts

		.end
