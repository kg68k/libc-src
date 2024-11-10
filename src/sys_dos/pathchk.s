* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: pathchk.s,v 1.3 1993/10/06 17:03:23 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_pathchk

		.offset		4

file:		.ds.l		1
comline:		.ds.l		1
envp:		.ds.l		1

		.text

__dos_pathchk:
		move.l		12(sp),-(sp)		* envp
		move.l		12(sp),-(sp)		* comline
		move.l		12(sp),-(sp)		* file
		move.w		#2,-(sp)
		dc.w		__EXEC
		lea.l		14(sp),sp
		rts

		.end
