# -*-Fundamental-*-
#
# PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
# --------------------------------------------------------------------
# This file is written by the Project C Library Group,  and completely
# in public domain. You can freely use, copy, modify, and redistribute
# the whole contents, without this notice.
# --------------------------------------------------------------------
# $Id: Makefile,v 1.4 1994/11/26 15:00:16 mura Exp $
#

   EXTRA_DEFINES = -SX
 EXTRA_LIBRARIES =
      LIB_TARGET = ../../lib/libc.a
         OBJECTS = _cplus.o _ctors.o _blkprof.o _dehupair.o _dumsig.o _enargv.o \
		   _exit.o _enhupair.o _fncprof.o _heapdef.o _heapsiz.o _main.o \
		   _pinfo.o _start.o _stack.o _stackdef.o _stacksiz.o _superman.o \
		   _vars.o _vector.o _sx_rinit.o _exec_kernel.o _getmem_size.o \
		   _sx_killheap.o _tsabort.o _objecttype.o _sxkerncom.o _common.o

include ../DefaultBases
include ../DefaultRules

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

%.o: ../startup/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: ../startup/%.s
	$(AS) $(ASFLAGS) -o $@ $<

_blkprof.o:	../startup/_blkprof.c
_cplus.o:	../startup/_cplus.c
_ctors.o:	../startup/_ctors.c
_dehupair.o:	../startup/_dehupair.c
_dumsig.o:	../startup/_dumsig.c
_enhupair.o:	../startup/_enhupair.c
_fncprof.o:	../startup/_fncprof.c
_heapdef.o:	../startup/_heapdef.s
_stackdef.o:	../startup/_stackdef.s
_vars.o:	../startup/_vars.c
_vector.o:	../startup/_vector.c
