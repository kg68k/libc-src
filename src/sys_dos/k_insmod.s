* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: k_insmod.s,v 1.3 1993/10/06 17:01:05 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_k_insmod

		.offset		4

n:		.ds.l		1

		.text

__dos_k_insmod:
		move.w		6(sp),-(sp)		* n
		move.w		#4,-(sp)
		dc.w		__KEYCTRL
		addq.w		#4,sp
		rts

		.end
