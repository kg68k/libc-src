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
* $Id: strmfe.s,v 1.2 1993/09/07 16:21:58 mura Exp $
*

		.xdef		_strmfe

		.xref		_strcpy
		.xref		__toslash
		.xref		__ctype_upper

		.offset		4

buffer:		.ds.l		1
name:		.ds.l		1
ext:		.ds.l		1

		.text

_strmfe:
		move.l		name(sp),-(sp)
		move.l		4+buffer(sp),-(sp)
		jsr		_strcpy
		jsr		__toslash
		addq.w		#8,sp
		movea.l		buffer(sp),a0
		movea.l		__ctype_upper,a1
		moveq.l		#0,d0
		move.b		(a0),d0
		beq		clear
		cmpi.b		#':',1(a0)
		bne		clear
		move.b		(a1,d0.w),(a0)
clear:
		moveq.l		#0,d1
sloop:
		move.b		(a0)+,d0
		beq		sloope
		cmpi.b		#'/',d0
		beq		clear
		cmpi.b		#'.',d0
		bne		sloop
		move.l		a0,d1
		bra		sloop
sloope:
		tst.l		d1
		beq		addext
		movea.l		d1,a0
addext:
		movea.l		ext(sp),a1
		move.b		(a1),-(a0)
		beq		end
		move.b		#'.',(a0)+
aloop:
		move.b		(a1)+,(a0)+
		bne		aloop
end:
		rts

		.end
