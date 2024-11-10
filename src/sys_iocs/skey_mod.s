* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: skey_mod.s,v 1.3 1993/10/06 17:18:04 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_skey_mod

		.offset		4

mode		.ds.l		1
x		.ds.l		1
y		.ds.l		1

		.text

__iocs_skey_mod:
		move.l		mode(sp),d1
		move.w		x+2(sp),d2
		swap.w		d2
		move.w		y+2(sp),d2
		iocs		__SKEY_MOD
		rts

		.end
