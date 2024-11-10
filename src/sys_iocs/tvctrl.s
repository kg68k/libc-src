* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: tvctrl.s,v 1.2 1993/10/06 17:20:13 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_tvctrl

		.offset		4

code		.ds.l		1

		.text

__iocs_tvctrl:
		move.l		code(sp),d1	* TV control code
		iocs		__TVCTRL
		rts

		.end
