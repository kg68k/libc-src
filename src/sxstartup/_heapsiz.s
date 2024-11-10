* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _heapsiz.s,v 1.1 1993/10/06 16:51:26 mura Exp $
*

		.xdef		__heapsize

		.xref		_HEAP_SIZE

		.rdata

__heapsize:	.dc.l		_HEAP_SIZE

		.end
