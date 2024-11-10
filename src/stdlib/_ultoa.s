* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _ultoa.s,v 1.1 1994/11/27 13:05:51 mura Exp $
*

		.xdef		__ultoa

NBYTES		.equ		5
NBITS		.equ		32

		.offset		8

val:		.ds.l		1
ptr:		.ds.l		1

		.text

__ultoa:
		movem.l		d3,-(sp)
		movem.l		val(sp),d1
		lea.l		bcd,a0			* バッファ初期化
		clr.w		0(a0)
		clr.l		2(a0)
		clr.l		6(a0)
		moveq.l		#NBITS-1,d0
bcd_loop_2:
		moveq.l		#NBYTES-1,d3
		adda.l		#NBYTES,a0
		lsl.l		#1,d1			* 64bitシフト
bcd_loop_1:
		move.b		-(a0),d2		* BCD演算
		abcd.b		d2,d2
		move.b		d2,(a0)
		dbra		d3,bcd_loop_1
		dbra		d0,bcd_loop_2
cnv:
		movea.l		ptr(sp),a1
		moveq.l		#NBYTES-1,d1
skip_dz:
		move.b		(a0)+,d2		* 0をスキップ
		bnz		skip_sz
		dbra		d1,skip_dz
		move.b		#'0',(a1)+
		bra		set_eos
skip_sz:
		move.b		d2,d3			* 上位の0をスキップ
		lsr.b		#4,d2
		bnz		cnv_upper
		andi.b		#15,d3
		addi.b		#'0',d3
		move.b		d3,(a1)+
		subq.l		#1,d1
		bcs		set_eos
cnv_loop:
		move.b		(a0)+,d2		* 通常変換
		move.b		d2,d3
		lsr.b		#4,d2
cnv_upper:
		addi.b		#'0',d2
		move.b		d2,(a1)+
		andi.b		#15,d3
		addi.b		#'0',d3
		move.b		d3,(a1)+
		dbra		d1,cnv_loop
set_eos:
		clr.b		(a1)
		movem.l		(sp)+,d3
		rts

		.bss

bcd:		.ds.b		10
end:

		.end
