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
* $Id: stcgfn.s,v 1.2 1993/09/07 16:21:43 mura Exp $
*

		.xdef		_stcgfn

		.xref		_strcpy
		.xref		__toslash

		.offset		0

pathbuff:	.ds.b		128
wksize:		.ds.l		1
extbuff:	.ds.l		1
name:		.ds.l		1

		.text

_stcgfn:
		lea.l		-wksize(sp),sp
		move.l		name(sp),-(sp)
		pea.l		4+pathbuff(sp)
		jsr		_strcpy
		jsr		__toslash
		lea.l		8+pathbuff(sp),a0
namest:
		move.l		a0,d1
		moveq.l		#0,d2
sloop:
		move.b		(a0)+,d0
		beq		end
		cmpi.b		#'/',d0
		beq		namest
		cmpi.b		#':',d0
		beq		namest
		cmpi.b		#'.',d0
		bne		sloop
		move.l		a0,d2
		bra		sloop
end:
		tst.l		d2
		beq		noext
		move.l		d2,a0
noext:
		clr.b		-(a0)
		move.l		a0,d0
		sub.l		d1,d0
		movea.l		d1,a0
copy:
		movea.l		8+extbuff(sp),a1
cloop:
		move.b		(a0)+,(a1)+
		bne		cloop
		lea.l		8+wksize(sp),sp
		rts

		.end
