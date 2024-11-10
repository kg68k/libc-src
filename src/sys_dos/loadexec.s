* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: loadexec.s,v 1.3 1993/10/06 17:02:08 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_loadexec

		.offset		4

file:		.ds.l		1
comline:	.ds.l		1
envptr:		.ds.l		1

		.text

__dos_loadexec:
		movem.l		d3-d7/a3-a6,-(sp)
		move.l		48(sp),-(sp)		* envptr
		move.l		48(sp),-(sp)		* comline
		move.l		48(sp),-(sp)		* file
		clr.w		-(sp)
		dc.w		__EXEC
		lea.l		14(sp),sp
		movem.l		(sp)+,d3-d7/a3-a6
		rts

		.end
