* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ledmod.s,v 1.2 1993/10/06 17:15:18 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_ledmod

		.offset		4

code		.ds.l		1
onoff		.ds.l		1

		.text

__iocs_ledmod:
		move.l		code(sp),d1	* led key code
		move.l		onoff(sp),d2	* on = 1, off = 0
		iocs		__LEDMOD
		rts

		.end
