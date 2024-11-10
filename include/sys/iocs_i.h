/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iocs_i.h,v 1.11 1994/07/27 13:44:54 mura Exp $
 */

#ifndef __sys_iocs_i_h__
#define __sys_iocs_i_h__

/*
 * IOCS コールをインライン展開するにはこの方法ではあまりうまくいかない
 * ことが多いようです (コードの質、潜在的なバグなど)。将来もっとまとも
 * な iocs_i.h を提供するまではこのインライン展開にはバグが潜んでいる
 * ものと思って使って下さい。
 */

#if !defined (__GNUC__) && !defined (__GNUG__)
#error You lose. This file can be compiled only by GNU-C compiler.
#endif

/*
 * The following functions cannot be inline-expanded.
 * Please use library version instead.
 *
 *	_iocs_bgscrlgt
 *	_iocs_sp_reggt
 */

static __inline int_ _iocs_adpcmsns (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__ADPCMSNS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ __const _iocs_akconv (int_ code, int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.w %1,d1\n\t"
		      "swap.w d1\n\t"
		      "move.w %2,d1\n\t"
		      "moveq.l #__AKCONV,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) code), "ri" ((short) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_alarmget (int_ *datetime, int_ *offtime, int_ *job)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__ALARMGET,%0\n\t"
		      "trap #15\n\t"
		      "movea.l %4,a0\n\t"
		      "move.l d0,(a0)\n\t"
		      "movea.l %5,a0\n\t"
		      "move.l d1,(a0)\n\t"
		      "movea.l %6,a0\n\t"
		      "move.l d2,(a0)"
			: "=d" (reg_d0), "=m" (*datetime), "=m" (*offtime), "=m" (*job)
			: "g" ((int_) datetime), "g" ((int_) offtime), "g" ((int_) job)
			: "d1", "d2", "a0");

    return reg_d0;
}

static __inline int_ _iocs_alarmmod (int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__ALARMMOD,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_alarmset (int_ datetime, int_ offtime, int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,a1\n\t"
		      "moveq.l #__ALARMSET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) datetime), "ri" ((int_) offtime), "ri" ((int_) mode)
			: "d1", "d2", "a1");

    return reg_d0;
}

static __inline int_ _iocs_apage (int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__APAGE,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_bgctrlgt (int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__BGCTRLGT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_bgctrlst (int_ mode, int_ page, int_ onoff)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "moveq.l #__BGCTRLST,%0\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) mode), "ri" ((int_) page), "ri" ((int_) onoff)
			: "d1", "d2", "d3");

    return reg_d0;
}

#if 0 /* non-local label is used inside the list... */
static __inline int_ _iocs_bgscrlgt (int_ mode, int_ *x, int_ *y)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %3,d1\n\t"
		      "moveq.l #__BGSCRLGT,d0\n\t"
		      "trap #15\n\t"
		      "cmp.l #0,d0\n\t"
		      "bne __iocs_c9_err\n\t"
		      "movea.l %4,a0\n\t"
		      "movea.l %5,a1\n\t"
		      "move.l d2,(a0)\n\t"
		      "move.l d3,(a1)\n"
		      "__iocs_c9_err:\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0), "=m" (*x), "=m" (*y)
			: /* no inputs */
			: "d1", "d2", "d3", "a0", "a1");

    return reg_d0;
}

#endif

static __inline int_ _iocs_bgscrlst (int_ mode, int_ x, int_ y)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "moveq.l #__BGSCRLST,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) mode), "ri" ((int_) x), "ri" ((int_) y)
			: "d1", "d2", "d3");

    return reg_d0;
}

static __inline int_ _iocs_bgtextcl (int_ page, int_ code)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__BGTEXTCL,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) page), "ri" ((int_) code)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_bgtextgt (int_ page, int_ x, int_ y)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "moveq.l #__BGTEXTGT,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) page), "ri" ((int_) x), "ri" ((int_) y)
			: "d1", "d2", "d3");

    return reg_d0;
}

static __inline int_ _iocs_bgtextst (int_ page, int_ x, int_ y, int_ code)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d4,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "move.l %4,d4\n\t"
		      "moveq.l #__BGTEXTST,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3-d4"
			: "=d" (reg_d0)
			: "ri" ((int_) page), "ri" ((int_) x), "ri" ((int_) y), "ri" ((int_) code)
			: "d1", "d2", "d3", "d4");

    return reg_d0;
}

static __inline int_ _iocs_bindatebcd (int_ bindate)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__DATEBCD,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) bindate)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_bindateget (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__DATEGET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_bitsns (int_ group)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__BITSNS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) group)
			: "d1");

    return reg_d0;
}

static __inline int_ __const _iocs_bootinf (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__BOOTINF,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_box (const struct _boxptr *boxptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__BOX,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) boxptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_assign (int_ drive, int_ recno, int_ icode, const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l  %1,d1\n\t"
		      "move.l  %2,d2\n\t"
		      "move.l  %3,d3\n\t"
		      "movea.l %4,a1\n\t"
		      "moveq.l #__B_ASSIGN,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) icode), "g" ((int_) addr)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_badfmt (int_ drive, int_ recno, int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "moveq.l #__B_BADFMT,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) mode)
			: "d1", "d2", "d3");

    return reg_d0;
}

static __inline int_ _iocs_b_bpeek (const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__B_BPEEK,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_color (int_ color)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__B_COLOR,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) color)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_b_consol (int_ xs, int_ ys, int_ xl, int_ yl)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.w %1,d1\n\t"
		      "swap.w d1\n\t"
		      "move.w %2,d1\n\t"
		      "move.w %3,d2\n\t"
		      "swap.w d2\n\t"
		      "move.w %4,d2\n\t"
		      "moveq.l #__B_CONSOL,%0\n\t"
		      "trap #15\n\t"
		      "move.l d2,%0"
			: "=d" (reg_d0)
			: "ri" ((short) xs), "ri" ((short) ys),
			  "ri" ((short) xl), "ri" ((short) yl)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_b_drvchk (int_ drive, int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__B_DRVCHK,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) mode)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_b_drvsns (int_ drive)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__B_DRVSNS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) drive)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_b_dskini (int_ drive, const void *addr, int_ offtm)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "movea.l %2,a1\n\t"
		      "move.l %3,d2\n\t"
		      "moveq.l #__B_DSKINI,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "g" ((int_) addr), "ri" ((int_) offtm)
			: "d1", "d2", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_eject (int_ drive)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__B_EJECT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) drive)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_b_format (int_ drive, int_ recno, int_ length, const void *idp)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l  %1,d1\n\t"
		      "move.l  %2,d2\n\t"
		      "move.l  %3,d3\n\t"
		      "movea.l %4,a1\n\t"
		      "moveq.l #__B_FORMAT,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) recno),
			  "ri" ((int_) length), "g" ((int_) idp)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_intvcs (int_ vector, int_ addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "movea.l %2,a1\n\t"
		      "moveq.l #__B_INTVCS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) vector), "g" ((int_) addr)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_super (int_ ssp)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l sp,a0\n\t"
		      "movea.l %1,a1\n\t"
		      "moveq.l #__B_SUPER,%0\n\t"
		      "trap #15\n\t"
		      "move.l a0,sp"
			: "=d" (reg_d0)
			: "g" ((int_) ssp)
			: "a0", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_keyinp (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__B_KEYINP,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_b_keysns (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__B_KEYSNS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_b_locate (int_ x, int_ y)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__B_LOCATE,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) x), "ri" ((int_) y)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_b_lpeek (const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__B_LPEEK,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_print (const char *msg)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__B_PRINT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) msg)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_putc (int_ code)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__B_PUTC,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) code)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_b_putmes (int_ color, int_ x, int_ y,
				    int_ max, const char *msg)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d4,-(sp)\n\t"
		      "move.l  %1,d1\n\t"
		      "move.l  %2,d2\n\t"
		      "move.l  %3,d3\n\t"
		      "move.l  %4,d4\n\t"
		      "move.l  %5,a1\n\t"
		      "moveq.l #__B_PUTMES,%0\n\t"
		      "trap #15\n\t"
		      "move.l d2,%0\n\t"
		      "movem.l (sp)+,d3-d4"
			: "=d" (reg_d0)
			: "ri" ((int_) color), "ri" ((int_) x), "ri" ((int_) y), "ri" ((int_) max), "g" ((int_) msg)
			: "d1", "d2", "d3", "d4", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_read (int_ drive,
				  int_ recno, int_ length, void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l  %2,d1\n\t"
		      "move.l  %3,d2\n\t"
		      "move.l  %4,d3\n\t"
		      "move.l  %5,a1\n\t"
		      "moveq.l #__B_READ,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0), "=m" (*(char *) addr)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) length), "g" ((int_) addr)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_readdi (int_ drive,
				     int_ recno, int_ length, void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l  %2,d1\n\t"
		      "move.l  %3,d2\n\t"
		      "move.l  %4,d3\n\t"
		      "move.l  %5,a1\n\t"
		      "moveq.l #__B_READDI,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0), "=m" (*(char *) addr)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) length), "g" ((int_) addr)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_readdl (int_ drive,
				     int_ recno, int_ length, void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l  %2,d1\n\t"
		      "move.l  %3,d2\n\t"
		      "move.l  %4,d3\n\t"
		      "move.l  %5,a1\n\t"
		      "moveq.l #__B_READDL,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0), "=m" (*(char *) addr)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) length), "g" ((int_) addr)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_readid (int_ drive, int_ track, void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %2,d1\n\t"
		      "move.l %3,%1\n\t"
		      "moveq.l #__B_READID,%0\n\t"
		      "trap #15\n\t"
		      "moveal. %4,a0\n\t"
		      "move.l d2,(a0)"
			: "=d" (reg_d0), "=m" (*(char *) addr)
			: "ri" ((int_) drive), "ri" ((int_) track), "g" ((int_) addr)
			: "d1", "d2", "a0");

    return reg_d0;
}

static __inline int_ _iocs_b_recali (int_ drive)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__B_RECALI,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) drive)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_b_seek (int_ drive, int_ recno)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__B_SEEK,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) recno)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_b_sftsns (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__B_SFTSNS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_b_verify (int_ drive,
				     int_ recno, int_ length, const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l  %1,d1\n\t"
		      "move.l  %2,d2\n\t"
		      "move.l  %3,d3\n\t"
		      "movea.l %4,a1\n\t"
		      "moveq.l #__B_VERIFY,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) length), "g" ((int_) addr)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_wpeek (const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__B_WPEEK,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_write (int_ drive,
				    int_ recno, int_ length, const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "move.l %4,a1\n\t"
		      "moveq.l #__B_WRITE,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) length), "g" ((int_) addr)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_b_writed (int_ drive,
				     int_ recno, int_ length, const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "move.l %4,a1\n\t"
		      "moveq.l #__B_WRITED,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) drive), "ri" ((int_) recno), "ri" ((int_) length), "g" ((int_) addr)
			: "d1", "d2", "d3", "a1");

    return reg_d0;
}

static __inline int_ _iocs_circle (const struct _circleptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__CIRCLE,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_contrast (int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__CONTRAST,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_crtcras (const void *addr, int_ luster)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "move.l  %2,d1\n\t"
		      "moveq.l #__CRTCRAS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr), "ri" ((int_) luster)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_crtmod (int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__CRTMOD,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_dakjob (char *bufend)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %2,a1\n\t"
		      "moveq.l #__DAKJOB,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*bufend)
			: "g" ((int_) bufend)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_dateasc (int_ bindate, char *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %2,d1\n\t"
		      "movea.l %3,a1\n\t"
		      "moveq.l #__DATEASC,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*addr)
			: "ri" ((int_) bindate), "g" ((int_) addr)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_datebin (int_ bcddate)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__DATEBIN,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) bcddate)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_datecnv (const char *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__DATECNV,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_defchr (int_ type, int_ code, const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.w %1,d1\n\t"
		      "swap.w d1\n\t"
		      "move.w %2,d1\n\t"
		      "movea.l %3,a1\n\t"
		      "moveq.l #__DEFCHR,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((short) type), "ri" ((short) code), "g" ((int_) addr)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_dmamode (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__DMAMODE,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_fill (const struct _fillptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__FILL,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_fntget (int_ type, int_ code, struct _fntbuf *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.w %2,d1\n\t"
		      "swap.w d1\n\t"
		      "move.w %3,d1\n\t"
		      "movea.l %4,a1\n\t"
		      "moveq.l #__FNTGET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*ptr)
			: "ri" ((short) type), "ri" ((short) code), "g" ((int_) ptr)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_getgrm (struct _getptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %2,a1\n\t"
		      "moveq.l #__GETGRM,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*ptr)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_gpalet (int_ no, int_ color)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__GPALET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) no), "ri" ((int_) color)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_hanjob (char *bufend)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %2,a1\n\t"
		      "moveq.l #__HANJOB,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*bufend)
			: "g" ((int_) bufend)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_home (int_ page, int_ x, int_ y)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "moveq.l #__HOME,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) page), "ri" ((int_) x), "ri" ((int_) y)
			: "d1", "d2", "d3");

    return reg_d0;
}

static __inline int_ __const _iocs_hsvtorgb (int_ h, int_ s, int_ v)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,%0\n\t"
		      "and.l #$ff,%0\n\t"
		      "swap.w %0\n\t"
		      "move.l %0,d1\n\t"
		      "move.l %2,%0\n\t"
		      "and.l #$1f,%0\n\t"
		      "rol.l #8,%0\n\t"
		      "or.l %0,d1\n\t"
		      "move.l %3,%0\n\t"
		      "and.l #$1f,%0\n\t"
		      "or.l %0,d1\n\t"
		      "moveq.l #__HSVTORGB,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) h), "ri" ((int_) s), "ri" ((int_) v)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_hsyncst (const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__HSYNCST,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_init_prn (int_ line, int_ width)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "and.l  #$ff,d1\n\t"
		      "rol.l  #8,d1\n\t"
		      "move.b %2,d1\n\t"
		      "moveq.l #__INIT_PRN,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) line), "ri" ((char) width)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_inp232c (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__INP232C,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_isns232c (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__ISNS232C,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ __const _iocs_jissft (int_ code)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__JISSFT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) code)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_joyget (int_ no)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__JOYGET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) no)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_line (const struct _lineptr *lineptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__LINE,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) lineptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_lof232c (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__LOF232C,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_ms_curgt (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__MS_CURGT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_ms_curst (int_ x, int_ y)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.w %1,d1\n\t"
		      "swap.w d1\n\t"
		      "move.w %2,d1\n\t"
		      "moveq.l #__MS_CURST,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((short) x), "ri" ((short) y)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_ms_getdt (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__MS_GETDT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_ms_limit (int_ xs, int_ ys, int_ xe, int_ ye)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.w %1,d1\n\t"
		      "swap.w d1\n\t"
		      "move.w %2,d1\n\t"
		      "move.w %3,d2\n\t"
		      "swap.w d2\n\t"
		      "move.w %4,d2\n\t"
		      "moveq.l #__MS_LIMIT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((short) xs), "ri" ((short) ys),
			  "ri" ((short) xe), "ri" ((short) ye)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_ms_offtm (int_ mode, int_ max)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__MS_OFFTM,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode), "ri" ((int_) max)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_ms_ontm (int_ mode, int_ max)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__MS_ONTM,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode), "ri" ((int_) max)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_ms_stat (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__MS_STAT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_ontime (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__ONTIME,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_opmintst (const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__OPMINTST,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_opmsns (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__OPMSNS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_osns232c (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__OSNS232C,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_paint (struct _paintptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__PAINT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_point (const struct _pointptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__POINT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_prnintst (const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__PRNINTST,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_pset (const struct _psetptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__PSET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_putgrm (const struct _putptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__PUTGRM,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_rmacnv (int_ code, char *wptr, char *aptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l  %3,d1\n\t"
		      "movea.l %4,a1\n\t"
		      "movea.l %5,a2\n\t"
		      "moveq.l #__RMACNV,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*wptr), "=m" (*aptr)
			: "ri" ((int_) code), "g" ((int_) wptr), "g" ((int_) aptr)
			: "d1", "a1", "a2");

    return reg_d0;
}

static __inline int_ __const _iocs_romver (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__ROMVER,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_set232c (int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__SET232C,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ __const _iocs_sftjis (int_ code)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__SFTJIS,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) code)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_skey_mod (int_ mode, int_ x, int_ y)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.w %2,d2\n\t"
		      "swap.w d2\n\t"
		      "move.w %3,d2\n\t"
		      "moveq.l #__SKEY_MOD,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode), "ri" ((short) x), "ri" ((short) y)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_snsprn (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__SNSPRN,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_spalet (int_ code, int_ block, int_ color)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "moveq.l #__SPALET,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: "=d" (reg_d0)
			: "ri" ((int_) code), "ri" ((int_) block), "ri" ((int_) color)
			: "d1", "d2", "d3");

    return reg_d0;
}

static __inline int_ _iocs_sp_cgclr (int_ code)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__SP_CGCLR,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) code)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_sp_defcg (int_ code, int_ size, const void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "movea.l %3,a1\n\t"
		      "moveq.l #__SP_DEFCG,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) code), "ri" ((int_) size), "g" ((int_) addr)
			: "d1", "d2", "a1");

    return reg_d0;
}

static __inline int_ _iocs_sp_gtpcg (int_ code, int_ size, void *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %2,d1\n\t"
		      "move.l %3,d2\n\t"
		      "movea.l %4,a1\n\t"
		      "moveq.l #__SP_GTPCG,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*(char *) addr)
			: "ri" ((int_) code), "ri" ((int_) size), "g" ((int_) addr)
			: "d1", "d2", "a1");

    return reg_d0;
}

static __inline int_ _iocs_sp_init (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__SP_INIT,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_sp_on (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__SP_ON,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

#if 0 /* non-local label is used inside the list... */
static __inline int_ _iocs_sp_reggt (int_ spno, int_ *x, int_ *y, int_ *code, int_ *prw)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d5/a3,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "moveq.l #__SP_REGGT,%0\n\t"
		      "trap #15\n\t"
		      "cmp.l #0,%0\n\t"
		      "bne __iocs_c7_err\n\t"
		      "movea.l %2,a0\n\t"
		      "movea.l %3,a1\n\t"
		      "movea.l %4,a2\n\t"
		      "movea.l %5,a3\n\t"
		      "move.l d2,(a0)\n\t"
		      "move.l d3,(a1)\n\t"
		      "move.l d4,(a2)\n\t"
		      "move.l d5,(a3)\n"
		      "__iocs_c7_err:\n\t"
		      "movem.l (sp)+,d3-d5/a3"
			: "=d" (reg_d0)
			: "ri" ((int_) spno), "g" ((int_) x), "g" ((int_) y),
			  "g" ((int_) code), "g" ((int_) prw)
			: "d1", "d2", "d3", "d4", "d5",
			  "a0", "a1", "a2", "a3");

    __asm __volatile (""
			: "=d" (reg_d0), "=m" (*x), "=m" (*y),
			  "=m" (*code), "=m" (*prw));

    return reg_d0;
}
#endif

static __inline int_ _iocs_sp_regst (int_ spno, int_ mode,
				     int_ x, int_ y, int_ code, int_ prw)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d5,-(sp)\n\t"
		      "move.l %2,d1\n\t"
		      "and.l #$80000000,d1\n\t"
		      "move.b %1,d1\n\t"
		      "move.l %3,d2\n\t"
		      "move.l %4,d3\n\t"
		      "move.l %5,d4\n\t"
		      "move.l %6,d5\n\t"
		      "moveq.l #__SP_REGST,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3-d5"
			: "=d" (reg_d0)
			: "ri" ((char) spno), "ri" ((int_) mode),
			  "ri" ((int_) x), "ri" ((int_) y),
			  "ri" ((int_) code), "ri" ((int_) prw)
			: "d1", "d2", "d3", "d4", "d5");

    return reg_d0;
}

static __inline int_ _iocs_symbol (const struct _symbolptr *ptr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__SYMBOL,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) ptr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_tgusemd (int_ tg, int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__TGUSEMD,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) tg), "ri" ((int_) mode)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_timeasc (int_ bintime, char *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %2,d1\n\t"
		      "move.l %3,a1\n\t"
		      "moveq.l #__TIMEASC,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0), "=m" (*addr)
			: "ri" ((int_) bintime), "g" ((int_) addr)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_timebcd (int_ bintime)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__TIMEBCD,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) bintime)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_timebin (int_ bcddate)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__TIMEBIN,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) bcddate)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_timecnv (const char *addr)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "moveq.l #__TIMECNV,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr)
			: "a1");

    return reg_d0;
}

static __inline int_ _iocs_timeget (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__TIMEGET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline int_ _iocs_timerdst (const void *addr, int_ mode, int_ cnt)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "move.l %2,d1\n\t"
		      "and.l #$ff,d1\n\t"
		      "rol.l #8,d1\n\t"
		      "move.b %3,d1\n\t"
		      "moveq.l #__TIMERDST,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr), "ri" ((int_) mode), "ri" ((char) cnt)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_tpalet (int_ no, int_ col)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__TPALET,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) no), "ri" ((int_) col)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_tpalet2 (int_ no, int_ col)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__TPALET2,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) no), "ri" ((int_) col)
			: "d1", "d2");

    return reg_d0;
}

static __inline int_ _iocs_trap15 (const struct _regs *in, struct _regs *out)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d7/a3-a6,-(sp)\n\t"
		      "movea.l %2,a0\n\t"
		      "movem.l (a0),d0-d7,a1-a6\n\t"
		      "trap #15\n\t"
		      "movea.l %3,a0\n\t"
		      "movem.l d0-d7/a1-a6,(a0)\n\t"
		      "movem.l (sp)+,d3-d7/a3-a6"
			: "=d" (reg_d0), "=m" (*out)
			: "g" ((int_) in), "g" ((int_) out)
			: "d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7",
			  "a0", "a1", "a2", "a3", "a4", "a5", "a6");

    return reg_d0;
}

static __inline int_ _iocs_vdispst (const void *addr, int_ mode, int_ cnt)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movea.l %1,a1\n\t"
		      "move.l %2,d1\n\t"
		      "and.l #$ff,d1\n\t"
		      "rol.l #8,d1\n\t"
		      "move.b %3,d1\n\t"
		      "moveq.l #__VDISPST,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "g" ((int_) addr), "ri" ((int_) mode), "ri" ((char) cnt)
			: "d1", "a1");

    return reg_d0;
}

static __inline int_ _iocs_vpage (int_ mode)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,d1\n\t"
		      "moveq.l #__VPAGE,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: "ri" ((int_) mode)
			: "d1");

    return reg_d0;
}

static __inline int_ _iocs_window (int_ sx, int_ sy, int_ ex, int_ ey)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d4,-(sp)\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "move.l %3,d3\n\t"
		      "move.l %4,d4\n\t"
		      "moveq.l #__WINDOW,%0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3-d4"
			: "=d" (reg_d0)
			: "ri" ((int_) sx), "ri" ((int_) sy), "ri" ((int_) ex), "ri" ((int_) ey)
			: "d1", "d2", "d3", "d4");

    return reg_d0;
}

static __inline int_ _iocs_wipe (void_)
{
    register unsigned int_ reg_d0 __asm ("d0");

    __asm __volatile ("moveq.l #__WIPE,%0\n\t"
		      "trap #15"
			: "=d" (reg_d0)
			: /* no inputs */ );

    return reg_d0;
}

static __inline void __volatile _iocs_abortjob (void_)
{
    __asm __volatile ("moveq.l #__ABORTJOB,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_abortrst (void_)
{
    __asm __volatile ("moveq.l #__ABORTRST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_adpcmain (const struct _chain *addr, int_ mode, int_ cnt)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__ADPCMAIN,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr), "ri" ((int_) mode), "ri" ((int_) cnt)
			: "d0", "d1", "d2", "a1");
}

static __inline void _iocs_adpcmaot (const struct _chain *addr, int_ mode, int_ cnt)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__ADPCMAOT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr), "ri" ((int_) mode), "ri" ((int_) cnt)
			: "d0", "d1", "d2", "a1");
}

static __inline void _iocs_adpcminp (void *addr, int_ mode, int_ len)
{
    __asm __volatile ("movea.l %1,a1\n\t"
		      "move.l %2,d1\n\t"
		      "move.l %3,d2\n\t"
		      "moveq.l #__ADPCMINP,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr)
			: "g" ((int_) addr), "ri" ((int_) mode), "ri" ((int_) len)
			: "d0", "d1", "d2", "a1");
}

static __inline void _iocs_adpcmlin (const struct _chain2 *addr, int_ mode)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "move.l %1,d1\n\t"
		      "moveq.l #__ADPCMLIN,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr), "ri" ((int_) mode)
			: "d0", "d1", "a1");
}

static __inline void _iocs_adpcmlot (const struct _chain2 *addr, int_ mode)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "move.l %1,d1\n\t"
		      "moveq.l #__ADPCMLOT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr), "ri" ((int_) mode)
			: "d0", "d1", "a1");
}

static __inline void _iocs_adpcmmod (int_ mode)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__ADPCMMOD,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) mode)
			: "d0", "d1");
}

static __inline void _iocs_adpcmout (const void *addr, int_ mode, int_ len)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "moveq.l #__ADPCMOUT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr), "ri" ((int_) mode), "ri" ((int_) len)
			: "d0", "d1", "d2", "a1");
}

static __inline void _iocs_bindateset (int_ bcddate)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__DATESET,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) bcddate)
			: "d0", "d1");
}

static __inline void _iocs_b_bpoke (void *addr, int_ data)
{
    __asm __volatile ("movea.l %1,a1\n\t"
		      "move.l %2,d1\n\t"
		      "moveq.l #__B_BPOKE,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr)
			: "g" ((int_) addr), "ri" ((int_) data)
			: "d0", "d1", "a1");
}

static __inline void _iocs_b_clr_al (void_)
{
    __asm __volatile ("move.l #2,d1\n\t"
		      "moveq.l #__B_CLR_ST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0", "d1");
}

static __inline void _iocs_b_clr_ed (void_)
{
    __asm __volatile ("clr.l d1\n\t"
		      "moveq.l #__B_CLR_ST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0", "d1");
}

static __inline void _iocs_b_clr_st (void_)
{
    __asm __volatile ("move.l #1,d1\n\t"
		      "moveq.l #__B_CLR_ST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0", "d1");
}

static __inline void _iocs_b_curoff (void_)
{
    __asm __volatile ("moveq.l #__B_CUROFF,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_b_curon (void_)
{
    __asm __volatile ("moveq.l #__B_CURON,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_b_del (int_ num)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__B_DEL,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) num)
			: "d0", "d1");
}

static __inline void _iocs_b_down (int_ num)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__B_DOWN,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) num)
			: "d0", "d1");
}

static __inline void _iocs_b_down_s (void_)
{
    __asm __volatile ("moveq.l #__B_DOWN_S,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_b_era_al (void_)
{
    __asm __volatile ("move.l #2,d1\n\t"
		      "moveq.l #__B_ERA_ST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0", "d1");
}

static __inline void _iocs_b_era_ed (void_)
{
    __asm __volatile ("clr.l d1\n\t"
		      "moveq.l #__B_ERA_ST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0", "d1");
}

static __inline void _iocs_b_era_st (void_)
{
    __asm __volatile ("move.l #1,d1\n\t"
		      "moveq.l #__B_ERA_ST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0", "d1");
}

static __inline void _iocs_b_ins (int_ num)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__B_INS,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) num)
			: "d0", "d1");
}

static __inline void _iocs_b_left (int_ num)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__B_LEFT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) num)
			: "d0", "d1");
}

static __inline void _iocs_b_lpoke (void *addr, int_ data)
{
    __asm __volatile ("movea.l %1,a1\n\t"
		      "move.l %2,d1\n\t"
		      "moveq.l #__B_LPOKE,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr)
			: "g" ((int_) addr), "ri" ((int_) data)
			: "d0", "d1", "a1");
}

static __inline void _iocs_b_memset (void *addr, const void *buf, int_ cnt)
{
    __asm __volatile ("movea.l %1,a1\n\t"
		      "movea.l %2,a2\n\t"
		      "move.l %3,d1\n\t"
		      "moveq.l #__B_MEMSET,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr)
			: "g" ((int_) addr), "g" ((int_) buf), "ri" ((int_) cnt)
			: "d0", "d1", "a1", "a2");
}

static __inline void _iocs_b_memstr (const void *addr, void *buf, int_ cnt)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "movea.l %1,a2\n\t"
		      "move.l  %2,d1\n\t"
		      "moveq.l #__B_MEMSTR,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr), "g" ((int_) buf), "ri" ((int_) cnt)
			: "d0", "d1", "a1", "a2");
}

static __inline void _iocs_b_right (int_ num)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__B_RIGHT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) num)
			: "d0", "d1");
}

static __inline void _iocs_b_up (int_ num)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__B_UP,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) num)
			: "d0", "d1");
}

static __inline void _iocs_b_up_s (void_)
{
    __asm __volatile ("moveq.l #__B_UP_S,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_b_wpoke (void *addr, int_ data)
{
    __asm __volatile ("movea.l %1,a1\n\t"
		      "move.l %2,d1\n\t"
		      "moveq.l #__B_WPOKE,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr)
			: "g" ((int_) addr), "ri" ((int_) data)
			: "d0", "d1", "a1");
}

static __inline void _iocs_clipput (int_ x, int_ y, const struct _fntbuf *buf1,
				    const struct _clipxy *buf2)
{
    __asm __volatile ("move.l  %0,d1\n\t"
		      "move.l  %1,d2\n\t"
		      "movea.l %2,a1\n\t"
		      "movea.l %3,a2\n\t"
		      "moveq.l #__CLIPPUT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) x), "ri" ((int_) y), "g" ((int_) buf1), "g" ((int_) buf2)
			: "d0", "d1", "d2", "a1", "a2");
}

static __inline void _iocs_dayasc (int_ binday, char *addr)
{
    __asm __volatile ("move.l  %1,d1\n\t"
		      "movea.l %2,a1\n\t"
		      "moveq.l #__DAYASC,d0\n\t"
		      "trap #15"
			: "=m" (*addr)
			: "ri" ((int_) binday), "g" ((int_) addr)
			: "d0", "d1", "a1");
}

static __inline void _iocs_densns (void_)
{
    __asm __volatile ("moveq.l #__DENSNS,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_dmamove (void *addr1, void *addr2,
				    int_ mode, int_ cnt)
{
    __asm __volatile ("movea.l %2,a1\n\t"
		      "movea.l %3,a2\n\t"
		      "move.l %4,d1\n\t"
		      "move.l %5,d2\n\t"
		      "moveq.l #__DMAMOVE,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr1), "=m" (*(char *) addr2)
			: "g" ((int_) addr1), "g" ((int_) addr2), "ri" ((int_) mode), "ri" ((int_) cnt)
			: "d0", "d1", "d2", "a1", "a2");
}

static __inline void _iocs_dmamov_a (const struct _chain *addr1, void *addr2,
				     int_ mode, int_ cnt)
{
    __asm __volatile ("movea.l %1,a1\n\t"
		      "movea.l %2,a2\n\t"
		      "move.l %3,d1\n\t"
		      "move.l %4,d2\n\t"
		      "moveq.l #__DMAMOV_A,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr2)
			: "g" ((int_) addr1), "g" ((int_) addr2), "ri" ((int_) mode), "ri" ((int_) cnt)
			: "d0", "d1", "d2", "a1", "a2");
}

static __inline void _iocs_dmamov_l (const struct _chain2 *addr1, void *addr2,
				     int_ mode)
{
    __asm __volatile ("movea.l %1,a1\n\t"
		      "movea.l %2,a2\n\t"
		      "move.l %3,d1\n\t"
		      "moveq.l #__DMAMOV_L,d0\n\t"
		      "trap #15"
			: "=m" (*(char *) addr2)
			: "g" ((int_) addr1), "g" ((int_) addr2), "ri" ((int_) mode)
			: "d0", "d1", "a1", "a2");
}

static __inline void _iocs_g_clr_on (void_)
{
    __asm __volatile ("moveq.l #__G_CLR_ON,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void __volatile _iocs_iplerr (void_)
{
    __asm __volatile ("moveq.l #__IPLERR,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_ledmod (int_ code, int_ onoff)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "move.l %1,d2\n\t"
		      "moveq.l #__LEDMOD,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) code), "ri" ((int_) onoff)
			: "d0", "d1", "d2");
}

static __inline void _iocs_ms_curof (void_)
{
    __asm __volatile ("moveq.l #__MS_CUROF,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_ms_curon (void_)
{
    __asm __volatile ("moveq.l #__MS_CURON,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_ms_init (void_)
{
    __asm __volatile ("moveq.l #__MS_INIT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_ms_patst (int_ no, const struct _patst *addr)
{
    __asm __volatile ("move.l  %0,d1\n\t"
		      "movea.l %1,a1\n\t"
		      "moveq.l #__MS_PATST,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) no), "g" ((int_) addr)
			: "d0", "d1", "a1");
}

static __inline void _iocs_ms_sel (int_ no)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__MS_SEL,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) no)
			: "d0", "d1");
}

static __inline void _iocs_ms_sel2 (const short *addr)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "moveq.l #__MS_SEL2,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr)
			: "d0", "a1");
}

static __inline void _iocs_opmset (int_ addr, int_ data)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "move.l %1,d2\n\t"
		      "moveq.l #__OPMSET,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) addr), "ri" ((int_) data)
			: "d0", "d1", "d2");
}

static __inline void _iocs_os_curof (void_)
{
    __asm __volatile ("moveq.l #__OS_CUROF,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_os_curon (void_)
{
    __asm __volatile ("moveq.l #__OS_CURON,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_out232c (int_ code)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__OUT232C,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) code)
			: "d0", "d1");
}

static __inline void _iocs_outlpt (int_ code)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__OUTLPT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) code)
			: "d0", "d1");
}

static __inline void _iocs_outprn (int_ code)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__OUTPRN,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) code)
			: "d0", "d1");
}

static __inline void _iocs_scroll (int_ mode, int_ x, int_ y)
{
    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %0,d1\n\t"
		      "move.l %1,d2\n\t"
		      "move.l %2,d3\n\t"
		      "moveq.l #__SCROLL,d0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: /* no outputs */
			: "ri" ((int_) mode), "ri" ((int_) x), "ri" ((int_) y)
			: "d0", "d1", "d2", "d3");
}

static __inline void _iocs_skeyset (int_ key)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__SKEYSET,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) key)
			: "d0", "d1");
}

static __inline void _iocs_sp_off (void_)
{
    __asm __volatile ("moveq.l #__SP_OFF,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: /* no inputs */
			: "d0");
}

static __inline void _iocs_tcolor (int_ color)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__TCOLOR,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) color)
			: "d0", "d1");
}

static __inline void _iocs_textget (int_ x, int_ y, struct _fntbuf *buf)
{
    __asm __volatile ("move.l %1,d1\n\t"
		      "move.l %2,d2\n\t"
		      "movea.l %3,a1\n\t"
		      "moveq.l #__TEXTGET,d0\n\t"
		      "trap #15"
			: "=m" (*buf)
			: "ri" ((int_) x), "ri" ((int_) y), "g" ((int_) buf)
			: "d0", "d1", "d2", "a1");
}

static __inline void _iocs_textput (int_ x, int_ y, const struct _fntbuf *buf)
{
    __asm __volatile ("move.l  %0,d1\n\t"
		      "move.l  %1,d2\n\t"
		      "movea.l %2,a1\n\t"
		      "moveq.l #__TEXTPUT,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) x), "ri" ((int_) y), "g" ((int_) buf)
			: "d0", "d1", "d2", "a1");
}

static __inline void _iocs_timeset (int_ bcdtime)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__TIMESET,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) bcdtime)
			: "d0", "d1");
}

static __inline void _iocs_tvctrl (int_ code)
{
    __asm __volatile ("move.l %0,d1\n\t"
		      "moveq.l #__TVCTRL,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "ri" ((int_) code)
			: "d0", "d1");
}

static __inline void _iocs_txbox (const struct _tboxptr *addr)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "moveq.l #__TXBOX,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr)
			: "d0", "a1");
}

static __inline void _iocs_txfill (const struct _txfillptr *addr)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "moveq.l #__TXFILL,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr)
			: "d0", "a1");
}

static __inline void _iocs_txrascpy (int_ sor_dst, int_ copy, int_ mode)
{
    __asm __volatile ("movem.l d3,-(sp)\n\t"
		      "move.l %0,d1\n\t"
		      "move.l %1,d2\n\t"
		      "move.l %2,d3\n\t"
		      "moveq.l #__TXRASCPY,d0\n\t"
		      "trap #15\n\t"
		      "movem.l (sp)+,d3"
			: /* no outputs */
			: "ri" ((int_) sor_dst), "ri" ((int_) copy), "ri" ((int_) mode)
			: "d0", "d1", "d2", "d3");
}

static __inline void _iocs_txrev (const struct _trevptr *addr)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "moveq.l #__TXREV,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr)
			: "d0", "a1");
}

static __inline void _iocs_txxline (const struct _xlineptr *addr)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "moveq.l #__TXXLINE,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr)
			: "d0", "a1");
}

static __inline void _iocs_txyline (const struct _ylineptr *addr)
{
    __asm __volatile ("movea.l %0,a1\n\t"
		      "moveq.l #__TXYLINE,d0\n\t"
		      "trap #15"
			: /* no outputs */
			: "g" ((int_) addr)
			: "d0", "a1");
}

#endif
