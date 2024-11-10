* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: open_pr.s,v 1.3 1993/10/06 17:03:19 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_open_pr

		.offset		4

name:		.ds.l		1
counter:	.ds.l		1
u_sp:		.ds.l		1
s_sp:		.ds.l		1
s_reg:		.ds.l		1
p_cnt:		.ds.l		1
buff:		.ds.l		1
sleep_time:	.ds.l		1

		.text

__dos_open_pr:
		move.l		32(sp),-(sp)		* sleep_time
		move.l		32(sp),-(sp)		* buff
		move.l		32(sp),-(sp)		* pc
		move.w		34(sp),-(sp)		* sr
		move.l		30(sp),-(sp)		* ssp
		move.l		30(sp),-(sp)		* usp
		move.w		32(sp),-(sp)		* counter
		move.l		28(sp),-(sp)		* name
		dc.w		__OPEN_PR
		lea.l		28(sp),sp
		rts

		.end
