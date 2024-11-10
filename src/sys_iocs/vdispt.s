* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: vdispt.s,v 1.2 1993/10/06 17:20:51 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_vdispst

		.offset		4

addr		.ds.l		1
mode		.ds.l		1
cnt		.ds.l		1

		.text

__iocs_vdispst:
		movea.l		addr(sp),a1	* addr
		move.l		mode(sp),d1
		moveq.l		#$ff,d0
		and.l		d0,d1
		rol.l		#8,d1		* 15-8 : mode
		move.b		cnt+3(sp),d1	*  0-7 : cnt
		iocs		__VDISPST
		rts

		.end
