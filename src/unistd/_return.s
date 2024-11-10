*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* based on the contribution from hupairlib by K.Abe (Abechan).
* --------------------------------------------------------------------
* $Id: _return.s,v 1.4 1994/05/02 17:05:18 mura Exp $
*

		.include	doscall.mac

		.xdef		__noexec_return

		.offset		8

dregbuf		.ds.l		1

		.offset		0

_d0		.ds.l		1
_d1		.ds.l		1
_d2		.ds.l		1
_d3		.ds.l		1
_d4		.ds.l		1
_d5		.ds.l		1
_d6		.ds.l		1
_d7		.ds.l		1
_a0		.ds.l		1
_a1		.ds.l		1
_a2		.ds.l		1
_a3		.ds.l		1
_a4		.ds.l		1
_a5		.ds.l		1
_a6		.ds.l		1

		.text

__noexec_return:
		link		a6,#0
		movem.l		d0-d7/a0-a5,-(sp)
		move.l		dregbuf(a6),a0
		move.l		_a0(a0),a0
		move.l		#ret,$14(a0)
		move.l		a7,$3c(a0)
		clr.w		-(sp)
		dc.w		__EXIT2

ret:
		movem.l	(sp)+,d0-d7/a0-a5
		unlk	a6
		rts

		.end
