* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: up_s.s,v 1.2 1993/10/06 17:20:46 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_up_s

		.text

__iocs_b_up_s:
		iocs		__B_UP_S
		rts

		.end
