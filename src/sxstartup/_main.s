* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: _main.s,v 1.3 1994/11/26 15:00:24 mura Exp $
*

		.include	doscall.mac
		.include	sxcall.mac

		.xdef		__main
		.xdef		__libc_release
		.xdef		__libc_version
		.xdef		libstack

		.xref		OBJECTTYPE
		.xref		_COMMON_SIZE
		.xref		_exec_kernel
		.xref		__start

		.text

mdHeader:
		.dc.l		OBJECTTYPE
		.dc.l		0
		.dc.l		__main_sx-mdHeader
		.dc.l		0
		.dc.l		_COMMON_SIZE
		.dc.l		0,0,0

__main:
		bra		__main_1
		dc.b		'#HUPAIR',0
		dc.b		'#LIBSXC',0

		.even

__main_1:
		lea		libstack,sp
		lea		16(a0),a0
		suba.l		a0,a1
		pea		(a1)
		pea		(a0)
		dc.w		__SETBLOCK
		jsr		_exec_kernel
__main_sx:
		lea		libstack,sp
		cmp.l		#$ffffdffe,d0		* ER_ABORT
		beq		__main_err
		movem.l		d0-d1/a1-a4,-(sp)
		pea		(sp)
		jsr		__start
__main_err:
		move.l		d0,-(sp)
		dc.w		__TSExit		* TSExit

		.data

__libc_release:	.dc.b		'Jafar',0
__libc_version:	.dc.b		'SX1.1.32',0

		.bss

		.ds.b		2048
libstack:

		.end		__main
