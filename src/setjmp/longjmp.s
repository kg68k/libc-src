* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: longjmp.s,v 1.1.1.1 1993/04/18 16:20:28 mura Exp $
*

		.xdef		_longjmp

		.offset		4

environment:	.ds.l		1
rval:		.ds.l		1

		.text

_longjmp:
		move.l		rval(sp),d0
		bne		do_jmp
		moveq.l		#1,d0
do_jmp:
		move.l		environment(sp),a0
		movem.l		(a0)+,d3-d7/a3-a7
		move.l		(a0),(sp)
		rts

		.end
