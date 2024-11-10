* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _stack.s,v 1.1 1993/10/06 16:51:41 mura Exp $
*

		.include	sxcall.equ

		.xdef		__stack_over

		.xref		libstack

		.text

__stack_over:
		lea.l		libstack,sp
		pea.l		errmsg
		move.w		#%10000001_00000001,-(sp)
		dc.w		__DMError
		addq.l		#6,sp
		move.w		#126,-(sp)
		dc.w		__TSExit

		.data

errmsg		.dc.b		'libc: stack overflow.',13,10,0

		.end
