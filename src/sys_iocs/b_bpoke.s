* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_bpoke.s,v 1.3 1993/10/06 17:08:06 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_bpoke

		.offset		4

addr		.ds.l		1
data		.ds.l		1

		.text

__iocs_b_bpoke:
		movea.l		addr(sp),a1
		move.l		data(sp),d1
		iocs		__B_BPOKE
		rts

		.end
