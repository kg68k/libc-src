* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: pset.s,v 1.3 1993/10/06 17:17:31 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_pset

		.offset		4

psetptr		.ds.l		1

		.text

__iocs_pset:
		movea.l		psetptr(sp),a1	* struct PSETPTR *
		iocs		__PSET
		rts

		.end
