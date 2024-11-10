* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bgctrlst.s,v 1.3 1993/10/06 17:11:57 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bgctrlst

		.offset		4+4	* d3

mode		.ds.l		1
page		.ds.l		1
onoff		.ds.l		1

		.text

__iocs_bgctrlst:
		movem.l		d3,-(sp)	* save regs
		movem.l		mode(sp),d1-d3
		iocs		__BGCTRLST
		movem.l		(sp)+,d3	* load regs
		rts

		.end
