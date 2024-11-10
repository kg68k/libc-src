* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: defchr.s,v 1.2 1993/10/06 17:13:40 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_defchr

		.offset		4

type:		.ds.l		1
code:		.ds.l		1
address:	.ds.l		1

		.text

__iocs_defchr:
		move.w		type+2(sp),d1	* d1 (31-16) : type
		swap.w		d1
		move.w		code+2(sp),d1	* d1 (15-0)  : code
		movea.l		address(sp),a1	* a1 : buffer address
		iocs		__DEFCHR
		rts

		.end
