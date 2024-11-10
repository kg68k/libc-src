* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: super.s,v 1.3 1993/10/06 17:05:07 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_super

		.offset		4

stack:		.ds.l		1

		.text

__dos_super:
		move.l		(sp)+,a2
		move.l		sp,a1
		dc.w		__SUPER
		move.l		a1,sp
		jmp		(a2)
		rts

		.end
