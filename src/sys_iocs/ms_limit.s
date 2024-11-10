* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: ms_limit.s,v 1.3 1993/10/06 17:15:58 mura Exp $
*

		.include	iocscall.mac

		.xdef		__iocs_ms_limit

		.offset		4

xs		.ds.l		1	* start
ys		.ds.l		1
xe		.ds.l		1	* end
ye		.ds.l		1

		.text

__iocs_ms_limit:
		move.w		xs+2(sp),d1	* start
		swap.w		d1
		move.w		ys+2(sp),d1
		move.w		xe+2(sp),d2	* end
		swap.w		d2
		move.w		ye+2(sp),d2
		iocs		__MS_LIMIT
		rts

		.end
