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
* $Id: strmfp.s,v 1.2 1993/09/07 16:22:08 mura Exp $
*

		.xdef		_strmfp

		.xref		_strcpy
		.xref		__toslash
		.xref		__ctype_upper

		.offset		4

buffer:		.ds.l		1
path:		.ds.l		1
name:		.ds.l		1

		.text

_strmfp:
		move.l		path(sp),-(sp)
		move.l		4+buffer(sp),-(sp)
		jsr		_strcpy
		jsr		__toslash
		addq.w		#8,sp
		movea.l		buffer(sp),a0
		movea.l		__ctype_upper,a1
		moveq.l		#0,d0
		move.b		(a0),d0
		beq		addname
		cmpi.b		#':',1(a0)
		bne		sloop
		move.b		(a1,d0.w),(a0)+
sloop:
		tst.b		(a0)+
		bne		sloop
		subq.w		#1,a0
		cmpi.b		#'/',-1(a0)
		beq		addname
		move.b		#'/',(a0)+
addname:
		movea.l		name(sp),a1
aloop:
		move.b		(a1)+,(a0)+
		bne		aloop
		rts

		.end
