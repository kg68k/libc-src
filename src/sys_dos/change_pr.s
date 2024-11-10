* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: change_pr.s,v 1.4 1993/10/06 16:54:29 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_change_pr

		.text

__dos_change_pr:
		dc.w		__CHANGE_PR
		rts

		.end
