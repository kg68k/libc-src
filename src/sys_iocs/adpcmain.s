* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: adpcmain.s,v 1.2 1993/10/06 17:06:43 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_adpcmain

		.offset		4

tbladdr		.ds.l		1
mode		.ds.l		1
tblcnt		.ds.l		1

		.text

__iocs_adpcmain:
		movea.l		tbladdr(sp),a1
		movem.l		mode(sp),d1-d2
		iocs		__ADPCMAIN
		rts

		.end
