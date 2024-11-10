* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _stack.s,v 1.3 1993/10/06 16:50:19 mura Exp $
*

		.include	doscall.mac

		.xdef		__stack_over

		.xref		libstack

		.text

__stack_over:
		lea.l		libstack,sp
		pea.l		errmsg
		dc.w		__PRINT
		addq.l		#4,sp
		move.w		#(1<<15).or.26,-(sp)
		dc.w		__EXIT2

		.data

errmsg		.dc.b		'libc: stack overflow.',13,10,0

		.end
