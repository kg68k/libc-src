* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _heapsiz.s,v 1.2 1993/09/16 15:27:20 mura Exp $
*

		.xdef		__heapsize

		.xref		_HEAP_SIZE

		.data

__heapsize:	.dc.l		_HEAP_SIZE

		.end
