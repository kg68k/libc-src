* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: abs.s,v 1.1.1.1 1993/04/18 16:23:56 mura Exp $
*

		.xdef		_abs
		.xdef		_labs

		.offset		4

val:		.ds.l		1

		.text

_abs:
_labs:
		move.l		val(sp),d0
		bpl		end
		neg.l		d0
end:
		rts

		.end
