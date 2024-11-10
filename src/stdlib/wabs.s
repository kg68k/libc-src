* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: wabs.s,v 1.1.1.1 1993/04/18 16:24:56 mura Exp $
*

		.xdef		_wabs

		.offset		4

val:		.ds.l		1

		.text

_wabs:
		move.w		val+2(sp),d0
		bpl		end
		neg.w		d0
		ext.l		d0
end:
		rts

		.end
