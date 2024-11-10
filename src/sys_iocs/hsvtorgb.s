* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: hsvtorgb.s,v 1.2 1993/10/06 17:14:40 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_hsvtorgb

		.offset		4

h		.ds.l		1
s		.ds.l		1
v		.ds.l		1

		.text

__iocs_hsvtorgb:
		move.l		h(sp),d0	* h get
		and.l		#$0ff,d0
		swap.w		d0
		move.l		d0,d1
		move.l		s(sp),d0	* s get
		and.l		#$01f,d0
		rol.l		#8,d0
		or.l		d0,d1		* h | s
		move.l		v(sp),d0	* v get
		and.l		#$01f,d0
		or.l		d0,d1		* h | s | v
		iocs		__HSVTORGB
		rts

		.end
