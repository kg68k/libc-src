* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bindno.s,v 1.3 1993/10/06 16:52:40 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_bindno

		.offset		4

file1:		.ds.l		1
file2:		.ds.l		1

		.text

__dos_bindno:
		movem.l		d3-d7/a3-a6,-(sp)
		clr.l		-(sp)
		move.l		48(sp),-(sp)		* file2
		move.l		48(sp),-(sp)		* file1
		move.w		#5,-(sp)
		dc.w		__EXEC
		lea.l		14(sp),sp
		movem.l		(sp)+,d3-d7/a3-a6
		rts

		.end
