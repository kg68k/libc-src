* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: home.s,v 1.3 1993/10/06 17:14:35 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_home

		.offset		4+4	* d3

page		.ds.l		1
x		.ds.l		1
y		.ds.l		1

		.text

__iocs_home:
		movem.l		d3,-(sp)	* save reg
		movem.l		page(sp),d1-d3
		iocs		__HOME
		movem.l		(sp)+,d3	* load reg
		rts

		.end
