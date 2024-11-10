# -*-Fundamental-*-
#
# PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
# --------------------------------------------------------------------
# This file is written by the Project C Library Group,  and completely
# in public domain. You can freely use, copy, modify, and redistribute
# the whole contents, without this notice.
# --------------------------------------------------------------------
# $Id: Makefile,v 1.8 1994/11/26 14:53:37 mura Exp $
#

   EXTRA_DEFINES =
 EXTRA_LIBRARIES =
      LIB_TARGET = ../../lib/libc.a
         OBJECTS = _fpuinit.o _fpuoff.o _fpuon.o _fpu_is68881.o \
		   _is68881.o _iscopro.o acos.o acosh.o asin.o asinh.o \
		   atan.o atan2.o atanh.o ceil.o cmpdf2.o cos.o cosh.o \
		   exp.o fabs.o floor.o fmod.o frexp.o isinf.o isnan.o \
		   ldexp.o log.o log10.o modf.o pow.o sin.o sinh.o \
		   sqrt.o tan.o tanh.o

all: $(OBJECTS)

_fpuinit.o: _fpuinit.c
	$(CC) $(CFLAGS) -S -o $*.fas $<
	$(FPPPCMD) -o $*.s $*.fas
	$(CC) $(CFLAGS) -o $@ -c $*.s
	$(RM) $*.s $*.fas

.SUFFIXES: .d

include ../DefaultBases
include ../DefaultRules

%.o: %.d
	$(SHELL) mathcc "$(CFLAGS)" $< $@
