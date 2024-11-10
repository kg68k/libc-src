* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: common_fre.s,v 1.3 1993/10/06 16:55:08 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_common_fre

		.offset		4

name:		.ds.l		1
pos:		.ds.l		1
id_psp:		.ds.l		1
len:		.ds.l		1

		.text

__dos_common_fre:
		move.l		16(sp),-(sp)		* len
		move.l		16(sp),-(sp)		* id_psp
		move.l		16(sp),-(sp)		* pos
		move.l		16(sp),-(sp)		* name
		move.w		#4,-(sp)
		dc.w		__COMMON
		lea.l		18(sp),sp
		rts

		.end
