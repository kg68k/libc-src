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
* $Id: strins.s,v 1.2 1993/09/07 16:21:53 mura Exp $
*

		.xdef		_strins

		.offset		4

sstring:	.ds.l		1
dstring:	.ds.l		1

		.text

_strins:
		movem.l		sstring(sp),d0-d1
		movea.l		d0,a0
lsloop:
		tst.b		(a0)+
		bne		lsloop
		subq.w		#1,a0
		sub.l		a0,d0
		neg.l		d0
		beq		strins_end
		move.l		d1,a1
ldloop:
		tst.b		(a1)+
		bne		ldloop
		sub.l		a1,d1
		lea.l		(a1,d0.l),a2
iloop:
		move.b		-(a1),-(a2)
		addq.l		#1,d1
		bne		iloop
cloop:
		move.b		-(a0),-(a2)
		subq.l		#1,d0
		bne		cloop
strins_end:
		rts

		.end
