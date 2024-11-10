* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: spalet.s,v 1.3 1993/10/06 17:18:54 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_spalet

		.offset		4+4	* d3

code		.ds.l		1
block		.ds.l		1
color		.ds.l		1

		.text

__iocs_spalet:
		movem.l		d3,-(sp)	* save regs
		movem.l		code(sp),d1-d3
		iocs		__SPALET
		movem.l		(sp)+,d3	* load regs
		rts

		.end
