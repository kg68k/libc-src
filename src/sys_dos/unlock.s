* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: unlock.s,v 1.3 1993/10/06 17:05:25 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_unlock

		.offset		4

fno:		.ds.l		1
offset:		.ds.l		1
len:		.ds.l		1

		.text

__dos_unlock:
		move.l		12(sp),-(sp)		* len
		move.l		12(sp),-(sp)		* offset
		move.w		14(sp),-(sp)		* fno
		move.w		#1,-(sp)
		dc.w		__LOCK
		lea.l		12(sp),sp
		rts

		.end
