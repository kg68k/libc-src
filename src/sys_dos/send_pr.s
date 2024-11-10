* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: send_pr.s,v 1.4 1993/10/06 17:04:30 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_send_pr

		.offset		4

my_id:		.ds.l		1
your_id:		.ds.l		1
command:		.ds.l		1
buff:		.ds.l		1
length:		.ds.l		1

		.text

__dos_send_pr:
		move.l		20(sp),-(sp)		* length
		move.l		20(sp),-(sp)		* buff
		move.w		22(sp),-(sp)		* command
		move.w		20(sp),-(sp)		* your_id
		move.w		18(sp),-(sp)		* my_id
		dc.w		__SEND_PR
		lea.l		14(sp),sp
		rts

		.end
