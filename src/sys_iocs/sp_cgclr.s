* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sp_cgclr.s,v 1.3 1993/10/06 17:18:18 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_sp_cgclr

		.offset		4

code		.ds.l		1

		.text

__iocs_sp_cgclr:
		move.l		code(sp),d1
		iocs		__SP_CGCLR
		rts

		.end
