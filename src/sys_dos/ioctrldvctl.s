* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ioctrldvctl.s,v 1.3 1993/10/06 17:00:08 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_ioctrldvctl

		.offset		4

drive:		.ds.l		1
f_code:		.ds.l		1
buff:		.ds.l		1

		.text

__dos_ioctrldvctl:
		move.l		12(sp),-(sp)		* buff
		move.w		14(sp),-(sp)		* f_code
		move.w		12(sp),-(sp)		* drive
		move.w		#12,-(sp)
		dc.w		__IOCTRL
		lea.l		10(sp),sp
		rts

		.end
