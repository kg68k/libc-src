* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: getdpb.s,v 1.3 1993/10/06 16:58:17 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_getdpb

		.offset		4

drive:		.ds.l		1
dpbptr:		.ds.l		1

		.text

__dos_getdpb:
		move.l		8(sp),-(sp)		* dpbptr
		move.w		10(sp),-(sp)		* drive
		dc.w		__GETDPB
		addq.w		#6,sp
		rts

		.end
