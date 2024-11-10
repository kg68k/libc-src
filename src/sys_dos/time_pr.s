* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: time_pr.s,v 1.4 1993/10/06 17:05:20 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_time_pr

		.text

__dos_time_pr:
		dc.w		__TIME_PR
		rts

		.end
