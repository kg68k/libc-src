* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _pinfo.s,v 1.2 1993/08/16 13:35:11 mura Exp $
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

		.xdef		__PSP		* これらは XC 互換のため
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

		.bss

__memcp:	.ds.l		1		* メモリ管理ポインタ
__PSP:						*
__procp:	.ds.l		1		* プロセス管理ポインタ
__PSTA:						*
__psta:		.ds.l		1		* TEXT セクション
__PEND:						*
__BSTA:						*
__bsta:		.ds.l		1		* BSS セクション
__BEND:						*
__DSTA:						*
__dsta:		.ds.l		1		* DATA セクション
__DEND:						*
__csta:		.ds.l		1		* 引数セクション
__vsta:		.ds.l		1		* 引数配列セクション
__esta:		.ds.l		1		* 環境セクション
__fsta:		.ds.l		1		* 環境配列セクション
__SSTA:						*
__ssta:		.ds.l		1		* スタックセクション
__SEND:						*
__HSTA:						*
__hsta:		.ds.l		1		* ヒープセクション
__HEND:						*
__last:		.ds.l		1		* プロセスの終り
__mmax:		.ds.l		1		* メモリブロックの最大位置
__SSP:		.ds.l		1		* スーパーバイザスタック

		.end
