* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: suspend_pr.s,v 1.4 1993/10/06 17:05:16 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_suspend_pr

		.offset		4

id:		.ds.l		1

		.text

__dos_suspend_pr:
		move.w		6(sp),-(sp)		* id
		dc.w		__SUSPEND_PR
		addq.w		#2,sp
		rts

		.end
