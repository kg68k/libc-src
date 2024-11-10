* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sp_regst.s,v 1.3 1993/10/06 17:18:49 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_sp_regst

		.offset		4+12		* d3-d5

spno		.ds.l		1
mode		.ds.l		1
x		.ds.l		1
y		.ds.l		1
code		.ds.l		1
prw		.ds.l		1

		.text

__iocs_sp_regst:
		movem.l		d3-d5,-(sp)		* save regs
		move.l		mode(sp),d1
		and.l		#$80000000,d1
		move.b		spno+3(sp),d1
		movem.l		x(sp),d2-d5
		iocs		__SP_REGST
		movem.l		(sp)+,d3-d5		* load regs
		rts

		.end
