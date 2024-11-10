* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: line.s,v 1.3 1993/10/06 17:15:22 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_line

		.offset		4

lineptr		.ds.l		1

		.text

__iocs_line:
		movea.l		lineptr(sp),a1
		iocs		__LINE
		rts

		.end
