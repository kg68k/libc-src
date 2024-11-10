* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: kill_pr.s,v 1.3 1993/10/06 17:01:59 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_kill_pr

		.text

__dos_kill_pr:
		dc.w		__KILL_PR
		rts

		.end
