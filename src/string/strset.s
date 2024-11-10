* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strset.s,v 1.1.1.1 1993/04/18 16:25:49 mura Exp $
*

		.xdef		_strset

		.offset		4

buffer:		.ds.l		1
character:	.ds.l		1

		.text

_strset:
		movea.l		buffer(sp),a0
		move.l		character(sp),d1
		tst.b		(a0)
		bze		end
set_loop:
		move.b		d1,(a0)+
		tst.b		(a0)
		bnz		set_loop
end:
		rts

		.end
