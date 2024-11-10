* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: joyget.s,v 1.3 1993/10/06 17:15:13 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_joyget

		.offset		4

no		.ds.l		1

		.text

__iocs_joyget:
		move.l		no(sp),d1	* joystick no
		iocs		__JOYGET
		rts

		.end
