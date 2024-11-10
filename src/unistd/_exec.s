*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* based on the contribution from hupairlib by K.Abe (Abechan).
* --------------------------------------------------------------------
* $Id: _exec.s,v 1.4 1994/05/02 17:05:03 mura Exp $
*

		.include	doscall.mac

		.xdef		__exec

		.offset		8

mode		.ds.l		1
fname		.ds.l		1
comptr		.ds.l		1
envptr		.ds.l		1
regptr		.ds.l		1

		.text

__exec:
		link		a6,#0
		movem.l		d1-d7/a0-a5,-(sp)
		move.l		a6,-(sp)
		movem.l		fname(a6),a0-a2
		movem.l		a0-a2,-(sp)
		move.w		mode+2(a6),-(sp)
		dc.w		__EXEC
		lea.l		14(sp),sp
		move.l		(sp)+,a6
		move.l		regptr(a6),a5
		movem.l		d0-d7/a0-a6,(a5)
		movem.l		(sp)+,d1-d7/a0-a5
		unlk		a6
		rts

		.end
