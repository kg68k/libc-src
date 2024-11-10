* -*-Fundamental-*-
*
* PROJECT ANSI/UNIX, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project ANSI/UNIX Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: phase.s,v 1.3 1993/10/06 17:22:00 mura Exp $
*

		.include	iocscall.mac

		.xdef		__scsi_phase

		.text

__scsi_phase:
		scsi		__S_PHASE
		rts

		.end
