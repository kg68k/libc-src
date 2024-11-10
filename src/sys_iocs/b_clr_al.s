* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_clr_al.s,v 1.2 1993/10/06 17:08:11 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_clr_al

		.text

__iocs_b_clr_al:
		move.l		#2,d1			* mode 2
		iocs		__B_CLR_ST
		rts

		.end
