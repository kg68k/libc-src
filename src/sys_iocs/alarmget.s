* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: alarmget.s,v 1.2 1993/10/06 17:07:28 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_alarmget

		.offset		4

datetime	.ds.l		1
offtime		.ds.l		1
job		.ds.l		1

		.text

__iocs_alarmget:
		iocs		__ALARMGET
		movem.l		datetime(sp),a0-a2
		move.l		d1,(a0)			* datetime
		move.l		d2,(a1)			* offtime
		move.l		d0,(a2)			* job
		rts

		.end
