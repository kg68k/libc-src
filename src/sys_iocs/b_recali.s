* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_recali.s,v 1.3 1993/10/06 17:11:01 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_recali

		.offset		4

drive		.ds.l		1

		.text

__iocs_b_recali:
		movem.l		drive(sp),d1	* drive no
		iocs		__B_RECALI
		rts

		.end
