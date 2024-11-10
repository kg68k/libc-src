* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _intrtc.s,v 1.5 1994/11/26 14:55:48 mura Exp $
*

		.include	doscall.mac
		.include	iocscall.mac

		.xdef		__intrtc
		.xdef		__alarm_on
		.xdef		__rtccnt
		.xdef		__rtcnxt
		.xdef		saved_sr
		.xdef		saved_sp
		.xdef		saved_usp

		.xref		__oldrtc
		.xref		__sigparse
		.xref		__sigsetcnt
		.xref		__signal

S_ALRM		.equ		$0107

RTC_MODE	.equ		$e8a01b
RTC_RESET_CTRL	.equ		$e8a01f
INDOS_FLAG	.equ		$1c08

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
srreg		.ds.w		1
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

usermode	macro
		and.w 		#.not.(1<<13),sr
		endm

supermode	macro
		pea.l		0.w
		dc.w		__SUPER
		endm

		.text

__intrtc:
		tst.l		__alarm_on		* alarm設定中か?
		beq		rteout			* 違う

		subq.l		#1,__rtccnt		* --count
		bpl		rteout			* != 0 -> rte
		clr.l		__rtccnt		* clear rtccnt
		tst.w		INDOS_FLAG		* check inDOS
		bze		ok_go
		move.l		#1,__rtccnt		* forcefully set to 1
		bra		rteout			* try next!!

ok_go:
		move.l		sp,saved_sp		* save sp
		movem.l		d0-d7/a0-a6,-(sp)
		move.w		srreg(sp),d2		* d2 = sr
		move.l		pcreg(sp),d1		* d1 = pc
		move.w		d2,saved_sr		* save sr
		move.l		usp,a4			* save usp
		move.l		a4,saved_usp

		move.b		RTC_RESET_CTRL,d0	* 16Hz stop
		andi.b		#$03,d0
		ori.b		#$0c,d0
		move.b		d0,RTC_RESET_CTRL

		move.l		sp,a3			* a3 = ssp
		move.l		usp,a4			* a4 = usp
*
* user stack
*
		usermode				* user mode
		link		a5,#-size		* struct info
		move.l		#S_ALRM,info_code(a7)	* info.code = S_ALRM
		move.l		d1,info_pc(a7)		* info.pc = d1(pc)
		move.l		a4,info_usp(a7)		* info.usp = usp
		move.w		d2,info_sr(a7)		* info.sr = d2(sr)
		sigparse	a7			* _sigparse (info)
		move.l		d0,d3
		bmi		unknown
		signal		a7			* _signal (info)
		move.l		d0,d3
unknown:
		unlk		a5
		supermode				* super visor
*
* supervisor stack
*
		move.l		a3,sp			* sp  = a3 (ssp)
		move.l		a4,usp			* usp = a4 (usp)
		tst.l		d3
		bmi		oldvec			* if (err)
		bnz		done
		moveq.l		#__ABORTJOB,d0
		trap		#15			* abortjob ()
done:
		move.l		__rtcnxt,d0		* get next interval
		ble		done2			* if next <= 0 then done2
		move.l		d0,-(sp)		* push arguments
		move.l		d0,-(sp)
		jsr		__sigsetcnt		* reset timer
		addq.l		#8,sp
done2:
		movem.l		(sp)+,d0-d7/a0-a6
rteout:
		rte
oldvec:
		movem.l		(sp)+,d0-d7/a0-a6
		move.l		__oldrtc,-(sp)
		rts					* jump to old verctor

		.bss

__alarm_on:	.ds.l		1			* alarmが有効かどうか
__rtccnt:	.ds.l		1
__rtcnxt:	.ds.l		1
saved_sr:	.ds.w		1
saved_sp:	.ds.l		1
saved_usp:	.ds.l		1

		.end
