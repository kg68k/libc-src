* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strupr.s,v 1.1.1.1 1993/04/18 16:25:59 mura Exp $
*

		.xdef		_strupr

		.xref		__ctype_upper

		.offset		4

string:		.ds.l		1

		.text

_strupr:
		move.l		string(sp),d0
		movea.l		d0,a0
		movea.l		__ctype_upper,a1
		moveq.l		#0,d1
		move.b		(a0),d1
		beq		end
upr_loop:
		move.b		(a1,d1.w),(a0)+
		move.b		(a0),d1
		bne		upr_loop
end:
		rts

		.end
