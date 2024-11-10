* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: alarmset.s,v 1.2 1993/10/06 17:07:39 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_alarmset

		.offset		4

datetime	.ds.l		1
offtime		.ds.l		1
mode		.ds.l		1

		.text

__iocs_alarmset:
		movem.l		datetime(sp),d1-d2/a1
		iocs		__ALARMSET
		rts

		.end
