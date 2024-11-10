* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _tsabort.s,v 1.1 1993/10/06 16:52:03 mura Exp $
*


		.xdef		_TSSetAbort
		.xdef		_TSAbort

		.xref		_exit

		.text

_TSSetAbort:
		move.l		abort_job(a5),d0	* d0.l = abort job adr
		move.l		4(sp),d1		* d1.l = new abort job adr
		ble		@f
		move.l		d1,abort_job(a5)
		move.l		8(sp),abort_param(a5)
@@:
		rts

_TSAbort:
		move.l		4(sp),d1
		move.l		abort_job(a5),a1
		move.l		a1,d0			* test a1
		bne		@f
		lea.l		_exit,a1
@@:
		move.l		abort_param(a5),-(sp)
		move.l		d1,-(sp)
		jsr		(a1)

		.rbss

abort_job:	.ds.l		1
abort_param:	.ds.l		1

		.end
