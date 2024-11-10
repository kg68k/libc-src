* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: crtcras.s,v 1.2 1993/10/06 17:13:04 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_crtcras

		.offset		4

addr		.ds.l		1
luster		.ds.l		1

		.text

__iocs_crtcras:
		movea.l		addr(sp),a1	* addr
		move.l		luster(sp),d1
		iocs		__CRTCRAS
		rts

		.end
