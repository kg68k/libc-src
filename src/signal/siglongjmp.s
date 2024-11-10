* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: siglongjmp.s,v 1.3 1993/10/06 16:50:04 mura Exp $
*

		.include	doscall.mac

		.xdef		_siglongjmp

		.xref		__sigmask
		.xref		saved_sr
		.xref		saved_sp
		.xref		saved_usp

		.offset		4

environment:	.ds.l		1
rval:		.ds.l		1

		.text

_siglongjmp:
		move.l		rval(sp),d0
		bne		do_jmp
		moveq.l		#1,d0
do_jmp:
		move.l		environment(sp),a0
		movem.l		(a0)+,d3-d7/a3-a7
		move.l		(a0)+,d0
		bmi		skiprestore
		move.l		d0,__sigmask
skiprestore:
		pea.l		0.w
		dc.w		__SUPER
		addq.l		#4,sp
		move.l		saved_sp,sp
		move.l		saved_usp,a1
		move.l		a1,usp
		move.w		saved_sr,(sp)
		move.l		(a0),2(sp)
		rte

		.end
