* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strcmp.s,v 1.1.1.1 1993/04/18 16:25:24 mura Exp $
*

		.xdef		_strcmp

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_strcmp:
		movem.l		string1(sp),a0/a1
		moveq.l		#0,d0
		moveq.l		#0,d1
cmp_loop:
		move.b		(a0)+,d0
		move.b		(a1)+,d1
		bze		end
		cmp.b		d1,d0
		beq		cmp_loop
end:
		sub.l		d1,d0
		rts

		.end
