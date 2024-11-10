* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: makeassign.s,v 1.3 1993/10/06 17:02:21 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_makeassign

		.offset		4

path1:		.ds.l		1
path2:		.ds.l		1
mode:		.ds.l		1

		.text

__dos_makeassign:
		move.w		14(sp),-(sp)		* mode
		move.l		10(sp),-(sp)		* path2
		move.l		10(sp),-(sp)		* path1
		move.w		#1,-(sp)
		dc.w		__ASSIGN
		lea.l		12(sp),sp
		rts

		.end
