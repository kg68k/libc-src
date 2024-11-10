# -*-Fundamental-*-
#
# PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
# --------------------------------------------------------------------
# This file is written by the Project C Library Group,  and completely
# in public domain. You can freely use, copy, modify, and redistribute
# the whole contents, without this notice.
# --------------------------------------------------------------------
# $Id: Makefile,v 1.7 1994/11/26 14:50:25 mura Exp $
#

include DefaultBases

        SUB_DIRS = assert conio ctype errno dirent fcntl ftw glob \
		   grp interrupt locale math pwd setjmp startup \
		   stdio stdlib string sys_doseml sys_locking \
		   sys_resources sys_stat sys_timeb sys_timers \
		   sys_utsname sys_wait time unistd utime audio \
		   cplus sys_dos sys_iocs mbctype mbstring profile \
		   sys_scsi signal super tzone wctype widec wstring

     ALL_TARGETS = $(foreach DIR,$(SUB_DIRS),$(DIR).stamp)
   CLEAN_TARGETS = $(foreach DIR,$(SUB_DIRS),$(DIR).clean)

.PHONY: all

all: $(ALL_TARGETS)

.SUFFIXES: .stamp

%.stamp:
	@( cd $(patsubst %.stamp,%,$@); \
	   if [ -f Makefile -a ! -f DO_NOT_USE_THESE ]; then \
		echo "COMPILING $@ ....."; \
		$(MAKE) all; \
	    else \
		echo "SKIP $@ ....."; \
	    fi )

.PHONY: clean

clean: $(CLEAN_TARGETS)

.SUFFIXES: .clean

%.clean:
	@( cd $(patsubst %.clean,%,$@); \
	   if [ -f Makefile -a ! -f DO_NOT_USE_THESE ]; then \
		echo "CLEANING $@ ....."; \
		$(MAKE) clean; \
	    else \
		echo "SKIP $@ ....."; \
	    fi )
