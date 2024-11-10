* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* based on the contribution by TomY.
* --------------------------------------------------------------------
* $Id: memicmp.s,v 1.3 1993/09/16 15:27:50 mura Exp $
*

		.xdef		_memicmp
		.xdef		_memcmpi

		.xref		__ctype_lower

		.offset		4

ptr1:		.ds.l		1
ptr2:		.ds.l		1
size:		.ds.l		1

		.text

_memicmp:
_memcmpi:
		movem.l		ptr1(sp),a0-a1
		move.l		size(sp),d2
		beq		equend
		movea.l		__ctype_lower,a2
		moveq.l		#0,d0
		moveq.l		#0,d1
loop:
		move.b		(a0)+,d0
		move.b		(a1)+,d1
		cmp.b		d1,d0
		beq		equal
		move.b		(a2,d0.w),d0
		sub.b		(a2,d1.w),d0
		bne		differ
equal:
		subq.l		#1,d2
		bne		loop
equend:
		moveq.l		#0,d0
		rts
differ:
		ext.w		d0
		ext.l		d0
		rts

		.end
