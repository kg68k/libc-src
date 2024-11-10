* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sigsetjmp.s,v 1.1.1.1 1993/04/18 16:21:22 mura Exp $
*

		.xdef		_sigsetjmp

		.xref		__sigmask

		.offset		4

environment:	.ds.l		1
savemask:	.ds.l		1

		.text

_sigsetjmp:
		move.l		environment(sp),a0
		lea.l		4*12(a0),a0
		move.l		__sigmask,d1
		tst.l		savemask(sp)
		bnz		save
		moveq.l		#$ff,d1
save:
		move.l		(sp),-(a0)
		move.l		d1,-(a0)
		movem.l		d3-d7/a3-a7,-(a0)
		moveq.l		#0,d0
		rts

		.end
