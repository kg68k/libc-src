* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* based on the contribution by TomY.
* --------------------------------------------------------------------
* $Id: qsort.s,v 1.2 1994/05/02 16:52:51 mura Exp $
*

		.xdef		_qsort

		.xref		_errno

~tmp		.reg		d0		* 汎用 1
~tmp2		.reg		d1		* 汎用 2
~mtmp		.reg		d1		* 乗算用 1
~mtmp2		.reg		d2		* 乗算用 2
~usize		.reg		d3		* 単位要素サイズ
~left		.reg		d4		* 左区間要素数
~num		.reg		d5		* 区間要素数
~tmp3		.reg		d6		* 汎用 3
~dbconst	.reg		d7		* dbra 定数
~tmpptr		.reg		a0		* 汎用ポインタ 1
~tmpptr2	.reg		a1		* 汎用ポインタ 2
~leftptr	.reg		a3		* 左ポインタ
~middleptr	.reg		a4		* しきい値ポインタ
~rightptr	.reg		a5		* 右ポインタ
~cmpfunc	.reg		a6		* 比較関数
~qstack		.reg		sp		* スタックポインタ

MULU_L		.macro		src,dst,srch,dsth
		swap.w		src
		move.w		src,srch
		swap.w		src
		swap.w		dst
		move.w		dst,dsth
		swap.w		dst
		mulu.w		dst,srch
		mulu.w		src,dsth
		mulu.w		src,dst
		swap.w		dst
		add.w		srch,dst
		add.w		dsth,dst
		swap.w		dst
		.endm

SWAPMEM		.macro		ptr1,ptr2,ctr,tmp,dbcon
		.local		loop
		subq.l		#1,ctr
loop:		move.b		(ptr1),tmp
		move.b		(ptr2),(ptr1)+
		move.b		tmp,(ptr2)+
		dbra		ctr,loop
		sub.l		dbcon,ctr
		bcc		loop
		.endm

		.offset		0

QS_saveregs:	.ds.l		8+7
QS_return:	.ds.l		1
QSARG_base:	.ds.l		1
QSARG_num:	.ds.l		1
QSARG_size:	.ds.l		1
QSARG_cmpfunc:	.ds.l		1

QS_SAVEREGS	.reg		d0-d7/a0-a6

EINVAL		.equ		14

		.text

_qsort:
		* レジスタの退避

		movem.l		QS_SAVEREGS,-(sp)

		* 要素数 0、1 個のチェック

		moveq.l		#1,~tmp
		cmp.l		QSARG_num(sp),~tmp
		beq		end
		bhi		error
quick_sort:
		* 引数のロード

		move.l		QSARG_num(sp),~num
		move.l		QSARG_size(sp),~usize
		movea.l		QSARG_cmpfunc(sp),~cmpfunc
		movea.l		QSARG_base(sp),~leftptr

		* 最終要素ポイントの計算

		move.l		~num,~tmp
		subq.l		#1,~tmp
		MULU_L		~usize,~tmp,~mtmp,~mtmp2
		lea.l		(~leftptr,~tmp.l),~rightptr

		* dbra 定数のセット

		move.l		#$0001_0000,~dbconst

		* スタックにストッパーを積む

		clr.l		-(~qstack)
		clr.l		-(~qstack)
		clr.l		-(~qstack)
qs_mloop:
		* 要素数 2 個のチェック

		moveq.l		#2,~tmp
		cmp.l		~tmp,~num
		beq		qs_two

		* 要素数 1、3 個のチェック

		moveq.l		#3,~tmp
		cmp.l		~tmp,~num
		bhi		qs_main
		bcs		qs_popstack
qs_three:
		* 要素数 3 個の特別処理

		lea.l		(~leftptr,~usize.l),~middleptr

		* 左側 2 個を比較

		move.l		~leftptr,-(sp)
		move.l		~middleptr,-(sp)
		jsr		(~cmpfunc)
		addq.l		#8,sp
		tst.l		d0
		bpl		qs_three_2

		* 交換する

		movea.l		~leftptr,~tmpptr
		movea.l		~middleptr,~tmpptr2
		move.l		~usize,~tmp
		SWAPMEM		~tmpptr,~tmpptr2,~tmp,~tmp2,~dbconst
qs_three_2:
		* 右側 2 個を比較

		move.l		~middleptr,-(sp)
		move.l		~rightptr,-(sp)
		jsr		(~cmpfunc)
		addq.l		#8,sp
		tst.l		d0
		bpl		qs_popstack

		* 交換する

		movea.l		~middleptr,~tmpptr
		move.l		~usize,~tmp
		SWAPMEM		~tmpptr,~rightptr,~tmp,~tmp2,~dbconst

		* 再び左側 2 個を比較にいく

		movea.l		~middleptr,~rightptr
qs_two:
		* 要素数 2 個の特別処理

		move.l		~leftptr,-(sp)
		move.l		~rightptr,-(sp)
		jsr		(~cmpfunc)
		addq.l		#8,sp
		tst.l		d0
		bpl		qs_popstack

		* 交換する

		move.l		~usize,~tmp
		SWAPMEM		~leftptr,~rightptr,~tmp,~tmp2,~dbconst
qs_popstack:
		* スタックから要素数・左右ポイントを取り出す

		movem.l		(~qstack)+,~num/~leftptr/~rightptr

		* ストッパーを取り出したら終わり

		move.l		~rightptr,~tmp
		beq		end

		* 要素数 2、3 個のチェック

		moveq.l		#3,~tmp
		cmp.l		~tmp,~num
		bcs		qs_two
		beq		qs_three
qs_main:
		* 要素数 4 個以上の処理

		* 左右ポイントの保存

		movem.l		~leftptr/~rightptr,-(sp)

		* しきい値ポイントの計算

		move.l		~leftptr,~tmp
		add.l		~rightptr,~tmp
		btst.l		#0,~num
		bne		qs_main_2
		sub.l		~usize,~tmp
qs_main_2:
		lsr.l		#1,~tmp
		movea.l		~tmp,~middleptr
		moveq.l		#0,~left

		* 要素の交換ループ
qs_sloop:
		* 左交換位置の探索ループ

		movem.l		~leftptr/~middleptr,-(sp)
		jsr		(~cmpfunc)
		move.l		d0,~tmp3
		bpl		qs_lloop_end
qs_lloop:
		addq.l		#1,~left
		adda.l		~usize,~leftptr
		movem.l		~leftptr/~middleptr,(sp)
		jsr		(~cmpfunc)
		move.l		d0,~tmp3
		bmi		qs_lloop
qs_lloop_end:
		* 右交換位置の探索ループ

		movem.l		~middleptr/~rightptr,(sp)
		jsr		(~cmpfunc)
		tst.l		d0
		bpl		qs_rloop_end
qs_rloop:
		suba.l		~usize,~rightptr
		movem.l		~middleptr/~rightptr,(sp)
		jsr		(~cmpfunc)
		tst.l		d0
		bmi		qs_rloop
qs_rloop_end:
		addq.l		#8,sp

		* 左右ポインタが一致・交差していたら終わり

		cmpa.l		~leftptr,~rightptr
		beq		qs_sloop_last_l
		bcs		qs_sloop_end
qs_swap:
		* 左右の要素が等しいなら交換しない

		or.l		d0,~tmp3
		bne		qs_swap_2
		adda.l		~usize,~leftptr
		bra		qs_swap_5

		* しきい値ポインタのチェックと更新
qs_swap_2:
		cmpa.l		~leftptr,~middleptr
		bne		qs_swap_3
		movea.l		~rightptr,~middleptr
		bra		qs_swap_4
qs_swap_3:
		cmpa.l		~rightptr,~middleptr
		bne		qs_swap_4
		movea.l		~leftptr,~middleptr
qs_swap_4:
		* 交換する

		movea.l		~rightptr,~tmpptr
		move.l		~usize,~tmp
		SWAPMEM		~leftptr,~tmpptr,~tmp,~tmp2,~dbconst
qs_swap_5:
		* ポインタを進める

		suba.l		~usize,~rightptr
		addq.l		#1,~left

		* 左右ポインタが一致・交差していないならループ

		cmpa.l		~leftptr,~rightptr
		bhi		qs_sloop
qs_sloop_last:
		bne		qs_sloop_end

		* 左右ポインタが一致なら

		move.l		~leftptr,-(sp)
		move.l		~middleptr,-(sp)
		jsr		(~cmpfunc)
		addq.l		#8,sp

		* その要素をどちらかの区間に入れる

		tst.l		d0
		bmi		qs_sloop_last_r
qs_sloop_last_l:
		addq.l		#1,~left
		adda.l		~usize,~leftptr
		bra		qs_sloop_end
qs_sloop_last_r:
		suba.l		~usize,~rightptr
qs_sloop_end:
		* この時点で左右ポインタは交差している

		* 元の区間の左右ポインタを取り出す

		movem.l		(sp)+,~tmp3/~tmpptr

		* 右区間要素数の計算

		sub.l		~left,~num

		* 左右区間要素数の比較

		cmp.l		~num,~left
		bcs		qs_right
qs_left:
		* 左区間の方が大きいなら右区間を先に処理する

		moveq.l		#1,~tmp
		cmp.l		~tmp,~left
		bls		qs_left_2

		* 左区間をスタックに積む

		movem.l		~left/~tmp3/~rightptr,-(~qstack)
qs_left_2:
		* 右区間をセットする

***		move.l		~num,~num
***		movea.l		~leftptr,~leftptr
		movea.l		~tmpptr,~rightptr
		bra		qs_mloop
qs_right:
		* 右区間の方が大きいなら左区間を先に処理する。

		moveq.l		#1,~tmp
		cmp.l		~tmp,~num
		bls		qs_right_2

		* 右区間をスタックに積む

		exg.l		~tmpptr,~leftptr
		movem.l		~num/~tmpptr/~leftptr,-(~qstack)
qs_right_2:
		* 左区間をセットする

		move.l		~left,~num
***		movea.l		~rightptr,~rightptr
		movea.l		~tmp3,~leftptr
		bra		qs_mloop
error:
		* エラーコードのセット

		moveq.l		#EINVAL,d0
		move.l		d0,_errno
end:
		* レジスタの復帰

		movem.l		(sp)+,QS_SAVEREGS
		rts

		.end
