* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: bgscrlgt.s,v 1.3 1993/10/06 17:12:02 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_bgscrlgt

		.offset		4+4	* d3

mode		.ds.l		1
x		.ds.l		1
y		.ds.l		1

		.text

__iocs_bgscrlgt:
		movem.l		d3,-(sp)	* save regs
		move.l		mode(sp),d1
		iocs		__BGSCRLGT
		cmp.l		#0,d0		* error check
		bne		__error_rtn
		movem.l		x(sp),a0-a1	* return value set address
		move.l		d2,(a0)		* x
		move.l		d3,(a1)		* y
__error_rtn:
		movem.l		(sp)+,d3	* load regs
		rts

		.end
