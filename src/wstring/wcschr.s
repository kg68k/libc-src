* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcschr.s,v 1.1.1.1 1993/04/18 16:41:53 mura Exp $
*

		.xdef		_wcschr

		.offset		4

string:		.ds.l		1
character:	.ds.l		1

		.text

_wcschr:
		move.l		string(sp),a0
		move.l		character(sp),d0
		move.l		(a0)+,d1
		beq		end
chr_loop:
		cmp.l		d0,d1
		beq		found
		move.l		(a0)+,d1
		bnz		chr_loop
end:
		tst.l		d0
		beq		found
		moveq.l		#0,d0
		rts
found:
		subq.w		#4,a0
		move.l		a0,d0
		rts

		.end
