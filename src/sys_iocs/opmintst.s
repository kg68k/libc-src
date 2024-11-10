* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: opmintst.s,v 1.2 1993/10/06 17:16:35 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_opmintst

		.offset		4

addr		.ds.l		1

		.text

__iocs_opmintst:
		movea.l		addr(sp),a1
		iocs		__OPMINTST
		rts

		.end
