* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: atoi.s,v 1.1.1.1 1993/04/18 16:24:00 mura Exp $
*

		.xdef		_atoi
		.xdef		_atol

		.offset		4

string:		.ds.l		1

		.text

_atoi:
_atol:
		movea.l		string(sp),a0
		moveq.l		#0,d0
		moveq.l		#0,d2
skip_loop:
		move.b		(a0)+,d1
		beq		exit_point
		cmpi.b		#' ',d1
		beq		skip_loop
		cmpi.b		#$09,d1
		beq		skip_loop
		cmpi.b		#'+',d1
		beq		nextfetch
		cmpi.b		#'-',d1
		bne		conversion
		moveq.l		#1,d2
nextfetch:
		move.b		(a0)+,d1
conversion:
		cmpi.b		#$30,d1
		bcs		exit_point
		cmpi.b		#$3a,d1
		bcc		exit_point
		andi.l		#$0f,d1
		add.l		d0,d0
		add.l		d0,d1
		lsl.l		#2,d0
		add.l		d1,d0
		bra		nextfetch
exit_point:
		tst.b		d2
		beq		return
		neg.l		d0
return:
		rts

		.end
