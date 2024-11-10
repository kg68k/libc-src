* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: txrascpy.s,v 1.3 1993/10/06 17:20:27 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_txrascpy

		.offset		4+4	* d3

sor_dst		.ds.l		1
copy		.ds.l		1
mode		.ds.l		1

		.text

__iocs_txrascpy:
		movem.l		d3,-(sp)	* save reg
		movem.l		sor_dst(sp),d1-d3
		iocs		__TXRASCPY
		movem.l		(sp)+,d3	* load reg
		rts

		.end
