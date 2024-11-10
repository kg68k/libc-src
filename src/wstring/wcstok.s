* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wcstok.s,v 1.1.1.1 1993/04/18 16:42:12 mura Exp $
*

		.xdef		_wcstok

		.offset		4
string		.ds.l		1
delim		.ds.l		1

		.text

_wcstok:
		movem.l		string(sp),d0/d2

		tst.l		d0
		bne		check_end
		move.l		last,d0
		beq		check_fail
check_end:
		move.l		d0,a1
loop1:
		move.l		(a1)+,d0
		beq		string_end
		move.l		d2,a0
loop1_loop:
		move.l		(a0)+,d1
		beq		loop1_end
		cmp.l		d0,d1
		bne		loop1_loop
		bra		loop1
loop1_end:
		lea		-4(a1),a2
loop2:
		move.l		(a1)+,d0
		beq		string_end2
		move.l		d2,a0
loop2_loop:
		move.l		(a0)+,d1
		beq		loop2
		cmp.l		d0,d1
		bne		loop2_loop
loop2_end:
		clr.l		-4(a1)
wcstok_end:
		move.l		a1,last
		move.l		a2,d0
		rts
check_fail:
string_end:
		suba.l		a2,a2
string_end2:
		suba.l		a1,a1
		bra		wcstok_end

		.bss

last:		.ds.l		1

		.end
