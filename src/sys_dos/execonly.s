* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: execonly.s,v 1.3 1993/10/06 16:56:53 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_execonly

		.offset		4

jmpaddr:		.ds.l		1

		.text

__dos_execonly:
		movem.l		d3-d7/a3-a6,-(sp)
		move.l		40(sp),-(sp)		* jmpaddr
		move.w		#4,-(sp)
		dc.w		__EXEC
		addq.w		#6,sp
		movem.l		(sp)+,d3-d7/a3-a6
		rts

		.end
