* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: rmacnv.s,v 1.3 1993/10/06 17:17:40 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_rmacnv

		.offset		4

code		.ds.l		1
wptr		.ds.l		1
aptr		.ds.l		1

		.text

__iocs_rmacnv:
		move.l		code(sp),d1
		movem.l		wptr(sp),a1-a2
		iocs		__RMACNV
		rts

		.end
