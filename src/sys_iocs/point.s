* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: point.s,v 1.3 1993/10/06 17:17:21 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_point

		.offset		4

pointptr	.ds.l		1

		.text

__iocs_point:
		movea.l		pointptr(sp),a1
		iocs		__POINT
		rts

		.end