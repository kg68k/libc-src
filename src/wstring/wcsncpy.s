* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcsncpy.s,v 1.1.1.1 1993/04/18 16:42:06 mura Exp $
*

		.xdef		_wcsncpy

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1
n:		.ds.l		1

		.text

_wcsncpy:
		movem.l		string1(sp),a0/a1
		move.l		a0,d0
		move.l		n(sp),d1
		ble		end
		subq.l		#1,d1
ncpy_loop:
		move.l		(a1)+,(a0)+
		dbze		d1,ncpy_loop
		bze		padding
		clr.w		d1
		subq.l		#1,d1
		bcc		ncpy_loop
end:
		rts

padding:
		subq.l		#1,d1
		bmi		end
		moveq.l		#0,d2
pad_loop:
		move.l		d2,(a0)+
		dbra		d1,pad_loop
		clr.w		d1
		subq.l		#1,d1
		bcc		pad_loop
		rts

		.end
