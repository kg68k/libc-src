* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: init_prn.s,v 1.3 1993/10/06 17:14:50 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_init_prn

		.offset		4

line:		.ds.l		1
width:		.ds.l		1

		.text

__iocs_init_prn:
		move.l		line(sp),d1	* line
		moveq.l		#$ff,d0
		and.l		d0,d1
		rol.l		#8,d1
		move.b		width+3(sp),d1	* width
		iocs		__INIT_PRN
		rts

		.end
