* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcsrchr.s,v 1.1.1.1 1993/04/18 16:42:09 mura Exp $
*

		.xdef		_wcsrchr

		.offset		4

string:		.ds.l		1
character:	.ds.l		1

		.text

_wcsrchr:
		movea.l		string(sp),a0
		move.l		character(sp),d1
		moveq.l		#0,d0
		move.l		(a0)+,d2
		bze		fin
rchr_loop:
		cmp.l		d1,d2
		bne		next
		move.l		a0,d0
		subq.l		#4,d0
next:
		move.l		(a0)+,d2
		bne		rchr_loop
fin:
		tst.l		d1
		bne		end
		move.l		a0,d0
		subq.l		#4,d0
end:
		rts

		.end
