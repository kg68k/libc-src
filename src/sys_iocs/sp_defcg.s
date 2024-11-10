* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sp_defcg.s,v 1.3 1993/10/06 17:18:22 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_sp_defcg

		.offset		4

code:		.ds.l		1
size:		.ds.l		1
addr:		.ds.l		1

		.text

__iocs_sp_defcg:
		movem.l		code(sp),d1-d2/a1
		iocs		__SP_DEFCG
		rts

		.end
