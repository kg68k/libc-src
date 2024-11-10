* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: box.s,v 1.3 1993/10/06 17:12:44 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_box

		.offset		4

boxptr		.ds.l		1

		.text

__iocs_box:
		movea.l		boxptr(sp),a1
		iocs		__BOX
		rts

		.end
