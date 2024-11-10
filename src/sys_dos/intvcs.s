* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: intvcs.s,v 1.3 1993/10/06 17:00:03 mura Exp $
*

		.include	doscall.mac

		.xdef		__dos_intvcs

*		.xref		__dos_super

		.offset		4

intno:		.ds.l		1
jobadr:		.ds.l		1

		.text

*
* intvcs の前後で super/user 切り替えを行うのは NewX 対応のため
*

__dos_intvcs:
		move.l		8(sp),-(sp)		* jobadr
		move.w		10(sp),-(sp)		* intno
		dc.w		__INTVCS		* intvcs()
		addq.w		#6,sp
		rts

		.end

* __dos_intvcs:
*		pea.l		0.w			* supervisor
*		jsr		__dos_super
*		addq.l		#4,sp
*		move.l		d0,-(sp)		* push usp
*
*		move.l		12(sp),-(sp)		* jobadr
*		move.w		14(sp),-(sp)		* intno
*		dc.w		__INTVCS		* intvcs()
*		addq.w		#6,sp
*		move.l		d0,d1
*
*		tst.l		(sp)			* usp>0 usermode
*		ble		nouser
*		jsr		__dos_super
* nouser:
*		addq.l		#4,sp
*		move.l		d1,d0
* end:
*		rts
*
*		.end
