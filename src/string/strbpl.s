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
* $Id: strbpl.s,v 1.2 1993/09/07 16:21:48 mura Exp $
*

		.xdef		_strbpl

		.offset		4

listptr:	.ds.l		1
ptrmax:		.ds.l		1
string:		.ds.l		1

		.text

_strbpl:
		movem.l		listptr(sp),a0-a2
		move.l		a1,d0
		tst.b		(a2)
		beq		null
ploop:
		subq.l		#1,d0
		bcs		end
		move.l		a2,(a0)+
sloop:
		tst.b		(a2)+
		bne		sloop
		tst.b		(a2)
		bne		ploop
null:
		sub.l		#1,d0
		bcs		end
		clr.l		(a0)
		not.l		d0
		add.l		a1,d0
end:
		rts

		.end
