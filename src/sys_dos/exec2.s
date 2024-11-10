* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: exec2.s,v 1.3 1993/10/06 16:56:48 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_exec2

		.offset		4

md:		.ds.l		1
file:		.ds.l		1
p1:		.ds.l		1
p2:		.ds.l		1

		.text

__dos_exec2:
		movem.l		d3-d7/a3-a6,-(sp)
		move.l		52(sp),-(sp)		* p2
		move.l		52(sp),-(sp)		* p1
		move.l		52(sp),-(sp)		* file
		move.w		54(sp),-(sp)		* md
		dc.w		__EXEC
		lea.l		14(sp),sp
		movem.l		(sp)+,d3-d7/a3-a6
		rts

		.end
