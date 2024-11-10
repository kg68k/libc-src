* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sleep_pr.s,v 1.4 1993/10/06 17:05:02 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_sleep_pr

		.offset		4

time:		.ds.l		1

		.text

__dos_sleep_pr:
		move.l		4(sp),-(sp)		* time
		dc.w		__SLEEP_PR
		addq.w		#4,sp
		rts

		.end
