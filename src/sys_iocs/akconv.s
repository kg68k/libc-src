* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: akconv.s,v 1.3 1993/10/06 17:07:23 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_akconv

		.offset		4

code		.ds.l		1
mode		.ds.l		1

		.text

__iocs_akconv:
		move.w		code+2(sp),d1
		swap.w		d1
		move.w		mode+2(sp),d1
		iocs		__AKCONV
		rts

		.end