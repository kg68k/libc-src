* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcsncmp.s,v 1.1.1.1 1993/04/18 16:42:04 mura Exp $
*

		.xdef		_wcsncmp

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1
n:		.ds.l		1

		.text

_wcsncmp:
		movem.l		string1(sp),a0/a1/a2
		move.l		a2,d2
		ble		equal
		subq.l		#1,d2
ncmp_loop:
		move.l		(a0)+,d0
		move.l		(a1)+,d1
		bze		end
		cmp.l		d1,d0
		dbne		d2,ncmp_loop
		bne		end
		clr.w		d2
		subq.l		#1,d2
		bcc		ncmp_loop
end:
		sub.l		d1,d0
		rts
equal:
		moveq.l		#0,d0
		rts

		.end
