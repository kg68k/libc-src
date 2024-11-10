* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: b_era_ed.s,v 1.2 1993/10/06 17:09:26 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_b_era_ed

		.text

__iocs_b_era_ed:
		clr.l		d1		* mode 0
		iocs		__B_ERA_ST
		rts

		.end
