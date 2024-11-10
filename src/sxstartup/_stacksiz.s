* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _stacksiz.s,v 1.1 1993/10/06 16:51:44 mura Exp $
*

		.xdef		__stacksize

		.xref		_STACK_SIZE

		.rdata

__stacksize:	.dc.l		_STACK_SIZE

		.end
