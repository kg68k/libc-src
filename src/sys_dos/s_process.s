* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: s_process.s,v 1.4 1993/10/06 17:04:21 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_s_process

		.offset		4

id:		.ds.l		1
start:		.ds.l		1
size:		.ds.l		1
i_len:		.ds.l		1

		.text

__dos_s_process:
		move.l		16(sp),-(sp)		* i_len
		move.l		16(sp),-(sp)		* size
		move.l		16(sp),-(sp)		* start
		move.w		18(sp),-(sp)		* id
		dc.w		__S_PROCESS
		lea.l		14(sp),sp
		rts

		.end
