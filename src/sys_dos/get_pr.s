* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: get_pr.s,v 1.4 1993/10/06 16:57:55 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_get_pr

		.offset		4

id:		.ds.l		1
buff:		.ds.l		1

		.text

__dos_get_pr:
		move.l		8(sp),-(sp)		* buff
		move.w		10(sp),-(sp)		* id
		dc.w		__GET_PR
		addq.w		#6,sp
		rts

		.end
