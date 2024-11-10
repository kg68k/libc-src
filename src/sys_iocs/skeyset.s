* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: skeyset.s,v 1.2 1993/10/06 17:18:09 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_skeyset

		.offset		4

keycode		.ds.l		1

		.text

__iocs_skeyset:
		move.l		keycode(sp),d1	* key code
		iocs		__SKEYSET
		rts

		.end
