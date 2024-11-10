* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_super.s,v 1.4 1994/05/02 17:19:57 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_super

		.offset		4

ssp		.ds.l		1

		.text

__iocs_b_super:
		movea.l		(sp)+,a2	* a2 = return address
		movea.l		sp,a0		* a0 = sp (keep stack)
		movea.l		(sp),a1		* a1 = ssp
		iocs		__B_SUPER
		movea.l		a0,sp
		jmp		(a2)		* return

		.end
