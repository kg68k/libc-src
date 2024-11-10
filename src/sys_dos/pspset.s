* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: pspset.s,v 1.3 1993/10/06 17:03:41 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_pspset

		.offset		4

pspadr:		.ds.l		1

		.text

__dos_pspset:
		move.l		4(sp),-(sp)		* pspadr
		dc.w		__PSPSET
		addq.w		#4,sp
		rts

		.end
