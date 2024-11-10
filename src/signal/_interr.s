* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _interr.s,v 1.7 1994/05/02 16:47:30 mura Exp $
*

		.include	doscall.mac
		.include	iocscall.mac

		.xdef		__interr
		.xdef		__doscall_escape
		.xdef		__harderror_return

		.xref		__olderr
		.xref		__pause
		.xref		__sigparse
		.xref		__signal
		.xref		saved_sp
		.xref		saved_sr
		.xref		saved_usp

*
* Human 68K work area
*

inDOS		.equ		$1c08
SSPTemporary	.equ		$1c5c

		.offset		0

trap_sr		.ds.w		1
trap_pc		.ds.l		1

		.offset		0

info_mode	.ds.l		1
info_code	.ds.l		1
info_must	.ds.l		1
info_pc		.ds.l		1
info_usp	.ds.l		1
info_sr		.ds.w		1
size:

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

usermode	macro
		and.w 		#.not.(1<<13),sr
		endm

supermode	macro
		pea.l		0.w
		dc.w		__SUPER
		endm

		.text

__interr:
		move.l		sp,saved_sp		* save sp
		movem.l		d0-d6/a0-a6,-(sp)
		move.l		sp,a3			* a3 = ssp
		move.l		usp,a4			* a4 = usp
		move.l		a4,saved_usp		* save usp
		move.l		trap_pc(a6),d1
		move.w		trap_sr(a6),d2
		move.w		d2,saved_sr		* save sr
*
* user stack
*
		usermode				* user mode
		link		a5,#-size		* struct info
		moveq.l		#0,d0
		move.w		d7,d0
		move.l		d0,info_code(a7)	* info.code = d7.w
		move.l 		d1,info_pc(a7)		* info.pc   = pc
		move.l		a4,info_usp(a7)		* info.usp  = usp
		move.w		d2,info_sr(a7)		* info.sr   = sr
		sigparse	a7			* _sigparse (info)
		move.l		d0,d3
		bmi		unknown
		signal		a7			* _signal (info)
		move.l		d0,d3
unknown:
		unlk		a5
interr_next:
		supermode				* super visor
*
* supervisor stack
*
		move.l		a3,sp			* sp  = a3 (ssp)
		move.l		a4,usp			* usp = a4 (usp)
		tst.l		d3
		bmi		oldvec			* if (err)
		move.l		d3,d7
		bnz		done
		moveq.l		#__ABORTJOB,d0
		trap		#15			* abortjob ()
done:
		movem.l		(sp)+,d0-d6/a0-a6
		rte
oldvec:
		movem.l		(sp)+,d0-d6/a0-a6
		move.l		__olderr,-(sp)
		rts					* jump to old verctor

*
* [無視]、[再試行]、[アボート] を選択し DOS CALL エラーハン
* ドラの trap 14 を終了させる
*

__harderror_return:
		move.l		d0,d3			* d3 = result
		bra		interr_next

*
* DOS CALL をエラーハンドラの内部で強制終了させる。結構危険な
* 気もしないでもない・・・
*

__doscall_escape:
		move.l		4(sp),d1		* dos return errcode
		supermode				* super visor
		move.l		d1,d0
		clr.w		inDOS			* inDOS flag clear
		move.l		SSPTemporary,sp		* sp = Human work sp
		move.l		a4,usp			* usp = a4(usp)
		movem.l		(sp)+,d1-d7/a0-a6
		rte

		.end
