* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _ulltoa.s,v 1.1 1994/11/26 14:58:18 mura Exp $
*

		.xdef		__ulltoa

NBYTES		.equ		10
NBITS		.equ		64

		.offset		8

val:		.ds.l		2
ptr:		.ds.l		1

		.text

__ulltoa:
		link		a6,#0
		movem.l		d3-d4,-(sp)
		movem.l		val(a6),d1-d2
		lea.l		bcd,a0			* バッファ初期化
		clr.w		0(a0)
		clr.l		2(a0)
		clr.l		6(a0)
		moveq.l		#NBITS-1,d0
bcd_loop_2:
		moveq.l		#NBYTES-1,d4
		adda.l		#NBYTES,a0
		lsl.l		#1,d1			* 64bitシフト
		roxl.l		#1,d2
bcd_loop_1:
		move.b		-(a0),d3		* BCD演算
		abcd.b		d3,d3
		move.b		d3,(a0)
		dbra		d4,bcd_loop_1
		dbra		d0,bcd_loop_2
cnv:
		movea.l		ptr(a6),a1
		moveq.l		#NBYTES-1,d2
skip_dz:
		move.b		(a0)+,d3		* 0をスキップ
		bnz		skip_sz
		dbra		d2,skip_dz
		move.b		#'0',(a1)+
		bra		set_eos
skip_sz:
		move.b		d3,d4			* 上位の0をスキップ
		lsr.b		#4,d3
		bnz		cnv_upper
		andi.b		#15,d4
		addi.b		#'0',d4
		move.b		d4,(a1)+
		subq.l		#1,d2
		bcs		set_eos
cnv_loop:
		move.b		(a0)+,d3		* 通常変換
		move.b		d3,d4
		lsr.b		#4,d3
cnv_upper:
		addi.b		#'0',d3
		move.b		d3,(a1)+
		andi.b		#15,d4
		addi.b		#'0',d4
		move.b		d4,(a1)+
		dbra		d2,cnv_loop
set_eos:
		clr.b		(a1)
		movem.l		(sp)+,d3-d4
		unlk		a6
		rts

		.bss

bcd:		.ds.b		10
end:

		.end
