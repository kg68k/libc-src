* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _stacksiz.s,v 1.2 1993/09/16 15:27:27 mura Exp $
*

		.xdef		__stacksize

		.xref		_STACK_SIZE

		.data

__stacksize:	.dc.l		_STACK_SIZE

		.end
