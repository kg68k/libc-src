* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: stricmp.s,v 1.3 1993/09/16 15:27:54 mura Exp $
*

		.xdef		_stricmp
		.xdef		_strcmpi
		.xdef		_strcasecmp

		.xref		__ctype_lower

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1

		.text

_stricmp:
_strcmpi:
_strcasecmp:
		movem.l		string1(sp),a0/a1
		movea.l		__ctype_lower,a2
		moveq.l		#0,d0
		moveq.l		#0,d1
cmp_loop:
		move.b		(a0)+,d0
		move.b		(a1)+,d1
		bze		end
		cmp.b		d1,d0
		beq		cmp_loop
		move.b		(a2,d0.w),d0
		move.b		(a2,d1.w),d1
		cmp.b		d1,d0
		beq		cmp_loop
end:
		sub.l		d1,d0
		rts

		.end
