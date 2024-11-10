* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: dakjob.s,v 1.3 1993/10/06 17:13:14 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_dakjob

		.offset		4

bufend		.ds.l		1

		.text

__iocs_dakjob:
		movea.l		bufend(sp),a1
		iocs		__DAKJOB
		rts

		.end
