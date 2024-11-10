* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strrev.s,v 1.2 1993/08/16 13:37:26 mura Exp $
*

		.xdef		_strrev

		.offset		4

string:		.ds.l		1

		.text

_strrev:
		move.l		string(sp),d0
		movea.l		d0,a0
		movea.l		d0,a1
len_loop:
		tst.b		(a1)+
		bne		len_loop
		move.l		a1,d2
		sub.l		a0,d2
		subq.l		#2,d2
		bmi		end
		lsr.l		#1,d2
		subq.l		#1,a1
rev_loop:
		move.b		-(a1),d1
		move.b		(a0),(a1)
		move.b		d1,(a0)+
		dbra		d2,rev_loop
		clr.w		d2
		subq.l		#1,d2
		bcc		rev_loop
end:
		rts

		.end
