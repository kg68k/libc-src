* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strchr.s,v 1.1.1.1 1993/04/18 16:25:23 mura Exp $
*

		.xdef		_strchr

		.offset		4

string:		.ds.l		1
character:	.ds.l		1

		.text

_strchr:
		move.l		string(sp),a0
		move.b		character+3(sp),d0
		move.b		(a0)+,d1
		beq		end
chr_loop:
		cmp.b		d0,d1
		beq		found
		move.b		(a0)+,d1
		bnz		chr_loop
end:
		tst.b		d0
		beq		found
		moveq.l		#0,d0
		rts
found:
		subq.w		#1,a0
		move.l		a0,d0
		rts

		.end
