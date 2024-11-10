* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strlwr.s,v 1.1.1.1 1993/04/18 16:25:36 mura Exp $
*

		.xdef		_strlwr

		.xref		__ctype_lower

		.offset		4

string:		.ds.l		1

		.text

_strlwr:
		move.l		string(sp),d0
		movea.l		d0,a0
		movea.l		__ctype_lower,a1
		moveq.l		#0,d1
		move.b		(a0),d1
		beq		end
lwr_loop:
		move.b		(a1,d1.w),(a0)+
		move.b		(a0),d1
		bne		lwr_loop
end:
		rts

		.end
