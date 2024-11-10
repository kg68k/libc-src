* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: memset.s,v 1.1.1.1 1993/04/18 16:25:18 mura Exp $
*

		.xdef		_memset

		.offset		4

buffer:		.ds.l		1
character:	.ds.l		1
n:		.ds.l		1

		.text

_memset:
		movem.l		buffer(sp),d0/d1/d2
		movea.l		d0,a0
*
		tst.l		d2
		beq		end
*
		btst.l		#0,d0
		beq		memset_even
		move.b		d1,(a0)+
		subq.l		#1,d2
		beq		end
memset_even:
		move.b		d1,d0
		lsl.w		#8,d1
		move.b		d0,d1
		move.w		d1,d0
		swap		d1
		move.w		d0,d1

		cmp.l		#$10000,d2
		bcc		memset_large
** d2.l < $10000...16 bytes per loop(4 registers)
		moveq.l		#%1111,d0
		and.b		d2,d0		*d0.l=rest
		eor.b		d0,d2		*n & ~%1111
		add.l		d2,a0		*last pos
** 先に余り部分の処理
		subq.b		#1,d0
		bmi		memset_s_no_rest
		move.l		a0,a2
@@:		move.b		d1,(a2)+
		dbra		d0,@b
memset_s_no_rest:
		lsr.w		#4,d2
		beq		memset_s_end
		subq.w		#1,d2

		move.l		d1,d0
		move.l		d1,a1
		move.l		d1,a2
@@:		movem.l		d0/d1/a1/a2,-(a0)		*4*4=16bytes
		dbra		d2,@b
memset_s_end:
		move.l		buffer(sp),d0
end:
		rts

** d2.l > $10000...32 bytes per loop(8 registers)
memset_large:
		moveq.l		#%11111,d0
		and.b		d2,d0		*d0.l=rest
		eor.b		d0,d2		*n & %11111
		add.l		d2,a0
** 先に余り部分の処理
		subq.b		#1,d0
		bmi		memset_l_no_rest
		move.l		a0,a2
@@:		move.b		d1,(a0)+
		dbra		d0,@b
		move.l		a2,a0
memset_l_no_rest:

		lsr.l		#5,d2		*$10000<d2だったから絶対にd2は0以上。
	*	beq		memset_l_end	*よって、このブランチはありえない。
		subq.l		#1,d2

		movem.l		d3-d6,-(sp)
		move.l		d1,d0
		move.l		d1,d3
		move.l		d1,d4
		move.l		d1,d5
		move.l		d1,d6
		move.l		d1,a1
		move.l		d1,a2
@@:		movem.l		d0/d1/d3/d4/d5/d6/a1/a2,-(a0)		*4*8=32bytes
		dbra		d2,@b
		clr.w		d2
		subq.l		#1,d2
		bcc		@b
		movem.l		(sp)+,d3-d6

memset_l_end:
		move.l		buffer(sp),d0
		rts


		.end


