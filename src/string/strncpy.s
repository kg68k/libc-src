* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: strncpy.s,v 1.1.1.1 1993/04/18 16:25:41 mura Exp $
*

		.xdef		_strncpy

		.offset		4

string1:	.ds.l		1
string2:	.ds.l		1
n:		.ds.l		1

		.text

_strncpy:
		movem.l		string1(sp),a0/a1
		move.l		a0,d0
		move.l		n(sp),d1
		ble		end
		subq.l		#1,d1
ncpy_loop:
		move.b		(a1)+,(a0)+
		dbze		d1,ncpy_loop
		bze		padding
		clr.w		d1		*-	swap.w		d1
		subq.l		#1,d1		*-	subq.w		#1,d1
		bcc		ncpy_loop	*-	bcs		end
						*-	swap.w		d1
						*-	bra		ncpy_loop
end:
		rts

padding:
		subq.l		#1,d1
		bmi		end
pad_loop:
		clr.b		(a0)+
		dbra		d1,pad_loop
		clr.w		d1		*-	swap.w		d1
		subq.l		#1,d1		*-	subq.w		#1,d1
		bcc		pad_loop	*-	bcs		end
						*-	swap.w		d1
						*-	bra		pad_loop
.if 1						*-
		rts				*-
.else						*-
		bra		end		*-
.endif						*-
		.end
