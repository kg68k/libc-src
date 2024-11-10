* -*-Fundamental-*-
*
* PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
* --------------------------------------------------------------------
* This file is written by the Project C Library Group,  and completely
* in public domain. You can freely use, copy, modify, and redistribute
* the whole contents, without this notice.
* --------------------------------------------------------------------
* $Id: atof.s,v 1.2 1993/06/22 07:14:35 mura Exp $
*

		.xdef		_atof

		.offset		4

string:		.ds.l		1

		.text

_atof:
		move.l		d3,a1
		movea.l		string(sp),a0
		dc.w		$fe22			* __STOD
		move.l		a1,d3
		rts

		.end
