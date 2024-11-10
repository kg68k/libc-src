* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _fpu_is68881.s,v 1.2 1993/09/07 16:19:07 mura Exp $
*

		.xdef		__f_is68881
		.xdef		__fpu_is68881

_FPU_ID		.equ		($00)
_FPU_IO		.equ		($00e9e000+_FPU_ID*$80)

		.text

__f_is68881:
		.dc.w	$f200,$5c01		; fmovecr.x	#$01,fp0
		.dc.w	$f227,$7400		; fmove.d	fp0,-(sp)
		.dc.w	$201f			; move.l	(sp)+,d0
		.dc.w	$221f			; move.l	(sp)+,d1
		.dc.w	$4e75			; rts

__fpu_is68881:
		lea.l		_FPU_IO,a0
		lea.l		$000a(a0),a1
		lea.l		$0010(a0),a2
		move.w		#$5c01,(a1)
@@:
		tst.w		(a0)
		bmi		@b
		move.w		#$7400,(a1)
@@:
		btst.b		#$04,(a0)
		beq		@b
		subq.l		#8,sp
		move.l		(a2),(sp)
		move.l		(a2),$0004(sp)
@@:
		tst.w		(a0)
		bmi		@b
		move.l		(sp)+,d0
		move.l		(sp)+,d1
		rts

		.end
