* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _main.s,v 1.13 1994/11/26 14:56:31 mura Exp $
*

		.xdef		__main
		.xdef		__libc_release
		.xdef		__libc_version
		.xdef		libstack

		.xref		__start

		.text

__main:
		bra		__main_1
		dc.b		'#HUPAIR',0
		dc.b		'#LIBCV1',0

		.even

__main_1:
		lea		libstack,sp
		move.l		a0,-(sp)
		jsr		__start

		.data

__libc_release:	.dc.b		'Jafar',0
__libc_version:	.dc.b		'1.1.32A',0

		.bss

		.ds.b		128
libstack:

		.end		__main
