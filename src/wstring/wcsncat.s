* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcsncat.s,v 1.1.1.1 1993/04/18 16:42:03 mura Exp $
*

		.xdef		_wcsncat

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1
n:		.ds.l		1

		.text

_wcsncat:
		movem.l		string1(sp),a0/a1
		move.l		a0,d0
		move.l		n(sp),d1
		ble		fin
		subq.l		#1,d1
skip_loop:
		tst.l		(a0)+
		bnz		skip_loop
		subq.l		#4,a0
cat_loop:
		move.l		(a1)+,d2
		bze		end
		move.l		d2,(a0)+
		dbra.w		d1,cat_loop
		clr.w		d1
		subq.l		#1,d1
		bcc		cat_loop
end:
		clr.l		(a0)
fin:
		rts

		.end
