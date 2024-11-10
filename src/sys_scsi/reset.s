* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: reset.s,v 1.3 1993/10/06 17:22:21 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_reset

		.text

__scsi_reset:
		scsi		__S_RESET
		rts

		.end
