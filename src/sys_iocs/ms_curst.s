* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ms_curst.s,v 1.3 1993/10/06 17:15:44 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_ms_curst

		.offset		4

x		.ds.l		1
y		.ds.l		1

		.text

__iocs_ms_curst:
		move.w		x+2(sp),d1
		swap.w		d1
		move.w		y+2(sp),d1
		iocs		__MS_CURST
		rts

		.end
