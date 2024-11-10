* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcslen.s,v 1.1.1.1 1993/04/18 16:42:01 mura Exp $
*

		.xdef		_wcslen

		.offset		4

string:		.ds.l		1

		.text

_wcslen:
		movea.l		string(sp),a0
		move.l		a0,d0
len_loop:
		tst.l		(a0)+
		bnz		len_loop
		subq.w		#4,a0
		sub.l		d0,a0
		move.l		a0,d0
		asr.l		#2,d0
		rts

		.end
