* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fnckeyst.s,v 1.3 1993/10/06 16:57:41 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fnckeyst

		.offset		4

fno:		.ds.l		1
buffer:		.ds.l		1

		.text

__dos_fnckeyst:
		move.l		8(sp),-(sp)		* buffer
		move.w		10(sp),d0		* fno
		or.w		#$100,d0
		move.w		d0,-(sp)
		dc.w		__FNCKEY
		addq.w		#6,sp
		rts

		.end
