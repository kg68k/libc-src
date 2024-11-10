* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: intlevel.s,v 1.3 1993/11/13 06:33:17 mura Exp $
*

		.include	doscall.mac

		.xdef		_intlevel

		.offset		4

level		.ds.l		1

		.text

_intlevel:
		pea.l		0.w		* スーパーバイザーへ
		dc.w		__SUPER
		addq.l		#4,sp
		move.l		d0,a0

		move.w		sr,d1		* 割り込みレベル変更
		move.w		sr,d2
		andi.w		#$f8ff,d2
		move.l		level(sp),d0
		andi.b		#$07,d0
		lsl.w		#8,d0
		or.w		d0,d2
		move.w		d2,sr
		lsr.w		#8,d1
		andi.l		#$07,d1

		move.l		a0,d0		* ユーザーモードへ
		ble		@f
		move.l		d0,-(sp)
		dc.w		__SUPER
		addq.l		#4,sp
@@:		move.l		d1,d0
		rts

		.end
