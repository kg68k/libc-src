* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: setjmp.s,v 1.1 1994/05/02 16:56:31 mura Exp $
*

		.xdef		_setjmp

		.xref		__sigmask

		.offset		4

environment:	.ds.l		1

		.text

_setjmp:
		move.l		environment(sp),a0
		lea.l		4*12(a0),a0
		move.l		(sp),-(a0)
		move.l		__sigmask,-(a0)
		movem.l		d3-d7/a3-a7,-(a0)
		moveq.l		#0,d0
		rts

		.end
