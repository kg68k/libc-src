* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bgtextst.s,v 1.3 1993/10/06 17:12:20 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bgtextst

		.offset		4+8	* d3-d4

page		.ds.l		1
x		.ds.l		1
y		.ds.l		1
code		.ds.l		1

		.text

__iocs_bgtextst:
		movem.l		d3-d4,-(sp)	* save regs
		movem.l		page(sp),d1-d4
		iocs		__BGTEXTST
		movem.l		(sp)+,d3-d4	* load regs
		rts

		.end
