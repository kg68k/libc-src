* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _intabt.s,v 1.3 1993/10/06 16:49:48 mura Exp $
*

		.include	doscall.mac

		.xdef		__intabt
		.xdef		__intrte

		.text

__intabt:
		move.w		#(1<<15).or.255,-(sp)
		dc.w		__EXIT2

__intrte:
		rte

		.end
