* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _intctl.s,v 1.3 1994/05/02 16:47:16 mura Exp $
*

		.include	iocscall.mac

		.xdef		__intctl

		.xref		__oldctl
		.xref		__sigparse
		.xref		__signal
		.xref		saved_sp
		.xref		saved_sr
		.xref		saved_usp

S_INT		.equ		$0104

		.offset		0

info_mode	.ds.l		1
info_code	.ds.l		1
info_must	.ds.l		1
info_pc		.ds.l		1
info_usp	.ds.l		1
info_sr		.ds.w		1
size:

		.offset		0

areg		.ds.l		7
dreg		.ds.l		8
pcreg		.ds.l		1

sigparse	macro 		val
		pea.l		(val)
		jsr		__sigparse
		addq.l		#4,sp
		endm

signal		macro 		val
		pea.l		(val)
		jsr		__signal
		addq.l		#4,sp
		endm

		.text

__intctl:
		move.l		sp,saved_sp		* save sp
		movem.l		d0-d7/a0-a6,-(sp)
		lea.l		pcreg(sp),a4		* a4 = sp
		move.l		(a4),d1			* d1 = pc

		link		a5,#-size		* struct info
		move.l		#S_INT,info_code(a7)	* info.code = S_INT
		move.l		d1,info_pc(a7)		* info.pc = d1(pc)
		move.l		a4,info_usp(a7)		* info.usp = usp
		move.l		a4,saved_usp		* save usp
		clr.w		info_sr(a7)		* info.sr = 0
		clr.w		saved_sr		* save sr
		sigparse	a7			* _sigparse (info)
		tst.l		d0
		bmi		unknown
		signal		a7			* _signal (info)
unknown:
		unlk		a5
		bmi		oldvec
*		bnz		done
		moveq.l		#__ABORTJOB,d0
		trap		#15			* abortjob ()
done:
oldvec:
		movem.l		(sp)+,d0-d7/a0-a6
		move.l		__oldctl,-(sp)
		rts					* jump to old verctor

		.end
