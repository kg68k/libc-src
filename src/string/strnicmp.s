* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strnicmp.s,v 1.2 1993/09/16 15:27:58 mura Exp $
*

		.xdef		_strnicmp
		.xdef		_strncasecmp

		.xref		__ctype_lower

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1
n:		.ds.l		1

		.text

_strnicmp:
_strncasecmp:
		movem.l		string1(sp),a0/a1/a2
		move.l		a2,d2
		ble		equal
		movea.l		__ctype_lower,a2
		subq.l		#1,d2
		moveq.l		#0,d0
		moveq.l		#0,d1
ncmp_loop:
		move.b		(a0)+,d0
		move.b		(a1)+,d1
		bze		end
		cmp.b		d1,d0
		beq		next
		move.b		(a2,d0.w),d0
		move.b		(a2,d1.w),d1
		cmp.b		d1,d0
next:
		dbne		d2,ncmp_loop
		bne		end
		clr.w		d2
		subq.l		#1,d2
		bcc		ncmp_loop
end:
		sub.l		d1,d0
		rts
equal:
		moveq.l		#0,d0
		rts

		.end
