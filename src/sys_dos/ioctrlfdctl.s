* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ioctrlfdctl.s,v 1.4 1994/11/26 15:02:32 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_ioctrlfdctl

		.offset		4

fno:		.ds.l		1
f_code:		.ds.l		1
buff:		.ds.l		1

		.text

__dos_ioctrlfdctl:
		move.l		12(sp),-(sp)		* buff
		move.w		14(sp),-(sp)		* f_code
		move.w		12(sp),-(sp)		* fno
		move.w		#13,-(sp)
		dc.w		__IOCTRL
		lea.l		10(sp),sp
		rts

		.end
