* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: fnckeygt.s,v 1.3 1993/10/06 16:57:37 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_fnckeygt

		.offset		4

fno:		.ds.l		1
buffer:		.ds.l		1

		.text

__dos_fnckeygt:
		move.l		8(sp),-(sp)		* buffer
		move.w		10(sp),-(sp)		* fno
		dc.w		__FNCKEY
		addq.w		#6,sp
		rts

		.end
