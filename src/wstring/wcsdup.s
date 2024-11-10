* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcsdup.s,v 1.2 1993/05/21 14:11:42 mura Exp $
*
		.xdef		_wcsdup
		.xref		_malloc

		.offset		4

string		.ds.l		1

		.text

_wcsdup:
		movea.l		string(sp),a0
		move.l		a0,d0
len_loop:
		tst.l		(a0)+
		bne		len_loop
		sub.l		d0,a0
		move.l		a0,d0
		move.l		d0,-(sp)
		jsr		_malloc
		addq.w		#4,sp
		tst.l		d0
		beq		wcsdup_end
		move.l		string(sp),a1
		move.l		d0,a0
cpy_loop:
		move.l		(a1)+,(a0)+
		bne		cpy_loop
wcsdup_end:
		rts

		.end
