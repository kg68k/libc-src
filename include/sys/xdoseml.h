/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: xdoseml.h,v 1.4 1993/08/16 13:32:41 mura Exp $
 */

#ifndef __sys_xdoseml_h__
#define __sys_xdoseml_h__

#if !defined (__GNUC__) && !defined (__GNUG__)
#error You lose. This file can be compiled only by GNU-C compiler.
#endif

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

/*
** should be defined when lndrv supports C interface.
*/
#undef LNDRV_C_FUNCTION

#define LNDRV_HEADER		 (0) /* LNDR */
#define LNDRV_VERSION		 (1) /* V110 */
#define OLD_CREATE_VECTOR	 (2)
#define OLD_OPEN_VECTOR		 (3)
#define OLD_DELETE_VECTOR	 (4)
#define OLD_MKDIR_VECTOR	 (5)
#define OLD_RMDIR_VECTOR	 (6)
#define OLD_CHDIR_VECTOR	 (7)
#define OLD_CHMOD_VECTOR	 (8)
#define OLD_FILES_VECTOR	 (9)
#define OLD_RENAME_VECTOR	(10)
#define OLD_NEWFILE_VECTOR	(11)
#define OLD_FATCHK_VECTOR	(12)
#define OLD_ASSIGN_VECTOR	(13)
#define RESERVE_2_VECTOR	(14)
#define RESERVE_3_VECTOR	(15)
#define REALPATHCPY_VECTOR	(16)
#define LFILES_VECTOR		(17)
#define OLD_LFILES_VECTOR	(18)
#define LINK_NEST_MAX		(19)
#define GETREALPATH_VECTOR	(20)
#define LCHMOD_VECTOR		(21)
#define LFATCHK_VECTOR		(22)
#define C_OLD_CREATEC		(23)
#define C_OLD_OPEN		(24)
#define C_OLD_DELETE		(25)
#define C_OLD_MKDIR		(26)
#define C_OLD_RMDIR		(27)
#define C_OLD_CHDIR		(28)
#define C_OLD_CHMOD		(29)
#define C_OLD_FILES		(30)
#define C_OLD_RENAME		(31)
#define C_OLD_NEWFILE		(32)
#define C_OLD_FATCHK		(33)
#define C_OLD_ASSIGN		(34)
#define C_REALPATHCPY		(35)
#define C_LFILES		(36)
#define C_GETREALPATH		(37)
#define C_LCHMOD		(38)
#define C_LFATCHK		(39)

typedef struct {
    char name1[8];
    char ext[3];
    unsigned char atr;
    char name2[10];
    unsigned short time;
    unsigned short date;
    unsigned short fatno;
    unsigned long length;
} dirbuf_t;

#define CALL_XPATHCPY(func, dst, src)				\
    ({								\
	register int_ __ret asm ("d0");				\
	asm volatile ("movem.l d1-d7/a0-a6,-(sp)\n\t"		\
		      "move.l %3,-(sp)\n\t"			\
		      "move.l %2,-(sp)\n\t"			\
		      "move.l %1,a0\n\t"			\
		      "jsr (a0)\n\t" 				\
		      "addq.l #8,sp\n\t"			\
		      "movem.l (sp)+,d1-d7/a0-a6\n\t"		\
		      : "=g" (__ret)				\
		      : "g" (func), "g" (dst), "g" (src)	\
		      : "d0"); __ret;				\
    })

#define CALL_XOPEN(func, file, mode)				\
    ({								\
	register int_ __ret asm ("d0");				\
	asm volatile ("movem.l d1-d7/a0-a6,-(sp)\n\t"		\
		      "move.w %3,-(sp)\n\t"			\
		      "move.l %2,-(sp)\n\t"			\
		      "move.l %1,a0\n\t"			\
		      "move.l sp,a6\n\t"			\
		      "jsr (a0)\n\t" 				\
		      "addq.l #6,sp\n\t"			\
		      "movem.l (sp)+,d1-d7/a0-a6\n\t"		\
		      : "=g" (__ret)				\
		      : "g" (func), "g" (file), "g" (mode)	\
		      : "d0"); __ret;				\
    })

#define CALL_XLFILES(func, buf, name, atr)			\
    ({								\
	register int_ __ret asm ("d0");				\
	asm volatile ("movem.l d1-d7/a0-a6,-(sp)\n\t"		\
		      "move.w %4,-(sp)\n\t"			\
		      "move.l %3,-(sp)\n\t"			\
		      "move.l %2,-(sp)\n\t"			\
		      "move.l %1,a0\n\t"			\
		      "jsr (a0)\n\t" 				\
		      "lea.l 10(sp),sp\n\t"			\
		      "movem.l (sp)+,d1-d7/a0-a6\n\t"		\
		      : "=g" (__ret)				\
		      : "g" (func), "g" (buf),			\
		        "g" (name), "g" (atr) 			\
		      : "d0"); __ret;				\
    })

#define CALL_XLFATCHK2(func, file, buf, len)   			\
    ({								\
	register int_ __ret asm ("d0");				\
	asm volatile ("movem.l d1-d7/a0-a6,-(sp)\n\t"		\
		      "move.w %2,-(sp)\n\t"			\
		      "move.l %3,a0\n\t"			\
		      "adda.l #$80000000,a0\n\t"		\
		      "move.l a0,-(sp)\n\t"			\
		      "move.l %4,-(sp)\n\t"			\
		      "move.l sp,a6\n\t"			\
		      "jsr    (%1)\n\t"				\
		      "lea.l 10(sp),sp\n\t"			\
		      "movem.l (sp)+,d1-d7/a0-a6\n\t"		\
		      :"=d" (__ret)				\
		      :"a" (func), "ri" (len), "g" (buf),	\
		       "g" (file)				\
		      : "d0", "a0"); __ret;    			\
    })

#endif
