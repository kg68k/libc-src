* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _pinfo.s,v 1.1 1993/10/06 16:51:37 mura Exp $
*

		.xdef		__memcp
		.xdef		__procp
		.xdef		__psta
		.xdef		__bsta
		.xdef		__dsta
		.xdef		__csta
		.xdef		__vsta
		.xdef		__esta
		.xdef		__fsta
		.xdef		__ssta
		.xdef		__hsta
		.xdef		__last
		.xdef		__mmax

		.xdef		__PSP
		.xdef		__PSTA
		.xdef		__PEND
		.xdef		__BSTA
		.xdef		__BEND
		.xdef		__DSTA
		.xdef		__DEND
		.xdef		__SSTA
		.xdef		__SEND
		.xdef		__HSTA
		.xdef		__HEND
		.xdef		__SSP

		.xdef		__rdsta
		.xdef		__rbsta
		.xdef		__rssta
		.xdef		__rldsta
		.xdef		__rlbsta
		.xdef		__rlssta
		.xdef		__data_hdl1
		.xdef		__data_hdl2
		.xdef		__common

		.rbss

__memcp:	.ds.l		1		* メモリ管理ポインタ
__PSP:
__procp:	.ds.l		1		* プロセス管理ポインタ
__PSTA:						*
__psta:		.ds.l		1		* TEXT セクション
__PEND:
__BSTA:
__bsta:		.ds.l		1		* BSS セクション
__BEND:
__DSTA:
__dsta:		.ds.l		1		* DATA セクション
__DEND:
__csta:		.ds.l		1		* 引数セクション
__vsta:		.ds.l		1		* 引数配列セクション
__esta:		.ds.l		1		* 環境セクション
__fsta:		.ds.l		1		* 環境配列セクション
__SSTA:						*
__ssta:		.ds.l		1		* スタックセクション
__SEND:
__HSTA:
__hsta:		.ds.l		1		* ヒープセクション
__HEND:
__last:		.ds.l		1		* プロセスの終り
__mmax:		.ds.l		1		* メモリブロックの最大位置
__SSP:		.ds.l		1		* スーパーバイザスタック

* SX-MODE での拡張

__rdsta:	.ds.l		1		* rdata セクション
__rbsta:	.ds.l		1		* rbss セクション
__rssta:	.ds.l		1		* rstack セクション
__rldsta:	.ds.l		1		* rldata セクション
__rlbsta:	.ds.l		1		* rlbss セクション
__rlssta:	.ds.l		1		* rlstack セクション
__data_hdl1:	.ds.l		1		* ワークエリアへのハンドル
__data_hdl2:	.ds.l		1		* スタック＆環境エリアへのハンドル
__common:	.ds.l		1		* コモンエリアへのポインタ

		.end
