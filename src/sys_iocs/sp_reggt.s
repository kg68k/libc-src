* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: sp_reggt.s,v 1.3 1993/10/06 17:18:45 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_sp_reggt

		.offset		4+16	* d3-d5/a3

spno		.ds.l		1
x		.ds.l		1
y		.ds.l		1
code		.ds.l		1
prw		.ds.l		1

		.text

__iocs_sp_reggt:
		movem.l		d3-d5/a3,-(sp)	* save regs
		move.l		spno(sp),d1	* spno
		iocs		__SP_REGGT
		cmp.l		#0,d0		* error check 0 = normal
		bne		__error_ret
		movem.l		x(sp),a0-a3	* return value set address
		move.l		d2,(a0)		* x
		move.l		d3,(a1)		* y
		move.l		d4,(a2)		* code
		move.l		d5,(a3)		* prw
__error_ret:
		movem.l		(sp)+,d3-d5/a3	* load regs
		rts

		.end
