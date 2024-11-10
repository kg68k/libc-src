* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strncmp.s,v 1.1.1.1 1993/04/18 16:25:40 mura Exp $
*

		.xdef		_strncmp

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1
n:		.ds.l		1

		.text

_strncmp:
		movem.l		string1(sp),a0/a1/a2
		move.l		a2,d2
		ble		equal
		subq.l		#1,d2
		moveq.l		#0,d0
		moveq.l		#0,d1
ncmp_loop:
		move.b		(a0)+,d0
		move.b		(a1)+,d1
		bze		end
		cmp.b		d1,d0
		dbne		d2,ncmp_loop
		bne		end
		clr.w		d2		*-	swap.w		d2
		subq.l		#1,d2		*-	subq.w		#1,d2
		bcc		ncmp_loop	*-	bcs		end
						*-	swap.w		d2
						*-	bra		ncmp_loop
end:
		sub.l		d1,d0
		rts
equal:
		moveq.l		#0,d0
		rts

		.end
