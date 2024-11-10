/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dos_i.h,v 1.14 1994/07/27 13:44:24 mura Exp $
 */

#ifndef __sys_dos_i_h__
#define __sys_dos_i_h__

#ifndef __GNUC__
#error You lose. This file can be compiled only by GNU-C compiler.
#endif

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

/*
 * In -SX mode, SXCALL token should be used instead of DOSCALL.
 */
#if defined (__LIBSXC__) || defined (__SX_INLINE__)
#define __DOSCALL __SXCALL
#endif

/*
 * Inline functions with DOSCALL extensions.
 */

__DOSCALL __volatile void _di_exit (void_);
static __inline void __volatile _dos_exit (void_)
{
    /* call function body */
    (void) _di_exit ();
}

__DOSCALL int_ _di_getchar (void_);
static __inline int_ _dos_getchar (void_)
{
    /* call function body */
    return _di_getchar ();
}

__DOSCALL void _di_putchar (short);
static __inline void _dos_putchar (int_ code)
{
    /* call function body */
    (void) _di_putchar ((short) code);
}

__DOSCALL int_ _di_cominp (void_);
static __inline int_ _dos_cominp (void_)
{
    /* call function body */
    return _di_cominp ();
}

__DOSCALL void _di_comout (short);
static __inline void _dos_comout (int_ code)
{
    /* call function body */
    (void) _di_comout ((short) code);
}

__DOSCALL void _di_prnout (short);
static __inline void _dos_prnout (int_ code)
{
    /* call function body */
    (void) _di_prnout ((short) code);
}

__DOSCALL int_ _di_inpout (short);
static __inline int_ _dos_inpout (int_ code)
{
    /* call function body */
    return _di_inpout ((short) code);
}

__DOSCALL int_ _di_inkey (void_);
static __inline int_ _dos_inkey (void_)
{
    /* call function body */
    return _di_inkey ();
}

__DOSCALL int_ _di_getc (void_);
static __inline int_ _dos_getc (void_)
{
    /* call function body */
    return _di_getc ();
}

__DOSCALL void _di_print (const char *);
static __inline void _dos_print (const char *string)
{
    /* call function body */
    (void) _di_print (string);
}

__DOSCALL int_ _di_gets (struct _inpptr *);
static __inline int_ _dos_gets (struct _inpptr *ptr)
{
    /* call function body */
    return _di_gets (ptr);
}

__DOSCALL int_ _di_keysns (void_);
static __inline int_ _dos_keysns (void_)
{
    /* call function body */
    return _di_keysns ();
}

__DOSCALL int_ _di_kflushgp (short);
static __inline int_ _dos_kflushgp (void_)
{
    /* call function body */
    return _di_kflushgp (1);
}

__DOSCALL int_ _di_kflushio (short, short);
static __inline int_ _dos_kflushio (int_ code)
{
    /* call function body */
    return _di_kflushio (6, (short) code);
}

__DOSCALL int_ _di_kflushin (short);
static __inline int_ _dos_kflushin (void_)
{
    /* call function body */
    return _di_kflushin (7);
}

__DOSCALL int_ _di_kflushgc (short);
static __inline int_ _dos_kflushgc (void_)
{
    /* call function body */
    return _di_kflushgc (8);
}

__DOSCALL int_ _di_kflushgs (short, struct _inpptr *);
static __inline int_ _dos_kflushgs (struct _inpptr *ptr)
{
    /* call function body */
    return _di_kflushgs (10, ptr);
}

__DOSCALL void _di_fflush (void);
static __inline void _dos_fflush (void_)
{
    /* call function body */
    (void) _di_fflush ();
}

__DOSCALL int_ _di_chgdrv (short);
static __inline int_ _dos_chgdrv (int_ drv)
{
    /* call function body */
    return _di_chgdrv ((short) drv);
}

__DOSCALL int_ _di_drvctrl (short);
static __inline int_ _dos_drvctrl (int_ mode, int_ drv)
{
    /* call function body */
    return _di_drvctrl ((short) ((mode << 8) + drv));
}

__DOSCALL int_ _di_consns (void_);
static __inline int_ _dos_consns (void_)
{
    /* call function body */
    return _di_consns ();
}

__DOSCALL int_ _di_prnsns (void_);
static __inline int_ _dos_prnsns (void_)
{
    /* call function body */
    return _di_prnsns ();
}

__DOSCALL int_ _di_cinsns (void_);
static __inline int_ _dos_cinsns (void_)
{
    /* call function body */
    return _di_cinsns ();
}

__DOSCALL int_ _di_coutsns (void_);
static __inline int_ _dos_coutsns (void_)
{
    /* call function body */
    return _di_coutsns ();
}

__DOSCALL int_ _di_fatchk (const char *, unsigned short *);
static __inline int_ _dos_fatchk (const char *file, unsigned short *bufptr)
{
    /* call function body */
    return _di_fatchk (file, bufptr);
}

__DOSCALL int_ _di_fatchk2 (const char *, unsigned short *, short);
static __inline int_ _dos_fatchk2 (const char *file, unsigned short *bufptr, int_ length)
{
    /* call function body */
    return _di_fatchk2 (file, (unsigned short *) ((unsigned long) bufptr | (1 << 31)), (short) length);
}

__DOSCALL int_ _di_hendspmo (short);
static __inline int_ _dos_hendspmo (void_)
{
    /* call function body */
    return _di_hendspmo (0);
}

__DOSCALL int_ _di_hendspmp (short, short, const char *);
static __inline int_ _dos_hendspmp (int_ pos, const char *mesptr)
{
    /* call function body */
    return _di_hendspmp (1, (short) pos, mesptr);
}

__DOSCALL int_ _di_hendspmr (short, short, const char *);
static __inline int_ _dos_hendspmr (int_ pos, const char *mesptr)
{
    /* call function body */
    return _di_hendspmr (2, (short) pos, mesptr);
}

__DOSCALL void _di_hendspmc (short);
static __inline void _dos_hendspmc (void_)
{
    /* call function body */
    (void) _di_hendspmc (3);
}

__DOSCALL int_ _di_hendspio (short);
static __inline int_ _dos_hendspio (void_)
{
    /* call function body */
    return _di_hendspio (4);
}

__DOSCALL int_ _di_hendspip (short, short, const char *);
static __inline int_ _dos_hendspip (int_ pos, const char *mesptr)
{
    /* call function body */
    return _di_hendspip (5, (short) pos, mesptr);
}

__DOSCALL int_ _di_hendspir (short, short, const char *);
static __inline int_ _dos_hendspir (int_ pos, const char *mesptr)
{
    /* call function body */
    return _di_hendspir (6, (short) pos, mesptr);
}

__DOSCALL void _di_hendspic (short, short);
static __inline void _dos_hendspic (int_ pos)
{
    /* call function body */
    (void) _di_hendspic (7, (short) pos);
}

__DOSCALL int_ _di_hendspso (short);
static __inline int_ _dos_hendspso (void_)
{
    /* call function body */
    return _di_hendspso (8);
}

__DOSCALL int_ _di_hendspsp (short, short, const char *);
static __inline int_ _dos_hendspsp (int_ pos, const char *mesptr)
{
    /* call function body */
    return _di_hendspsp (9, (short) pos, mesptr);
}

__DOSCALL int_ _di_hendspsr (short, short, const char *);
static __inline int_ _dos_hendspsr (int_ pos, const char *mesptr)
{
    /* call function body */
    return _di_hendspsr (10, (short) pos, mesptr);
}

__DOSCALL void _di_hendspsc (short);
static __inline void _dos_hendspsc (void_)
{
    /* call function body */
    (void) _di_hendspsc (11);
}

__DOSCALL int_ _di_curdrv (void_);
static __inline int_ _dos_curdrv (void_)
{
    /* call function body */
    return _di_curdrv ();
}

__DOSCALL int_ _di_getss (struct _inpptr *);
static __inline int_ _dos_getss (struct _inpptr *inpptr)
{
    /* call function body */
    return _di_getss (inpptr);
}

__DOSCALL int_ _di_fgetc (short);
static __inline int_ _dos_fgetc (int_ fno)
{
    /* call function body */
    return _di_fgetc ((short) fno);
}

__DOSCALL int_ _di_fgets (struct _inpptr *, short);
static __inline int_ _dos_fgets (struct _inpptr *inpptr, int_ fno)
{
    /* call function body */
    return _di_fgets (inpptr, (short) fno);
}

__DOSCALL void _di_fputc (short, short);
static __inline void _dos_fputc (int_ code, int_ fno)
{
    /* call function body */
    (void) _di_fputc ((short) code, (short) fno);
}

__DOSCALL void _di_fputs (const char *, short);
static __inline void _dos_fputs (const char *mesptr, int_ fno)
{
    /* call function body */
    (void) _di_fputs (mesptr, (short) fno);
}

__DOSCALL void _di_allclose (void_);
static __inline void _dos_allclose (void_)
{
    /* call function body */
    (void) _di_allclose ();
}

__DOSCALL void _di_fnckeygt (short, char *);
static __inline void _dos_fnckeygt (int_ fno, char *buffer)
{
    /* call function body */
    (void) _di_fnckeygt ((short) fno, buffer);
}

__DOSCALL void _di_fnckeyst (short, const char *);
static __inline void _dos_fnckeyst (int_ fno, const char *buffer)
{
    /* call function body */
    (void) _di_fnckeyst ((short) (fno + 0x100), buffer);
}

__DOSCALL int_ _di_c_putc (short, short);
static __inline int_ _dos_c_putc (int_ code)
{
    /* call function body */
    return _di_c_putc (0, (short) code);
}

__DOSCALL int_ _di_c_print (short, const char *);
static __inline int_ _dos_c_print (const char *msgptr)
{
    /* call function body */
    return _di_c_print (1, msgptr);
}

__DOSCALL int_ _di_c_color (short, short);
static __inline int_ _dos_c_color (int_ attr)
{
    /* call function body */
    return _di_c_color (2, (short) attr);
}

__DOSCALL int_ _di_c_locate (short, short, short);
static __inline int_ _dos_c_locate (int_ x, int_ y)
{
    /* call function body */
    return _di_c_locate (3, (short) x, (short) y);
}

__DOSCALL int_ _di_c_down_s (short);
static __inline int_ _dos_c_down_s (void_)
{
    /* call function body */
    return _di_c_down_s (4);
}

__DOSCALL int_ _di_c_up_s (short);
static __inline int_ _dos_c_up_s (void_)
{
    /* call function body */
    return _di_c_up_s (5);
}

__DOSCALL int_ _di_c_up (short, short);
static __inline int_ _dos_c_up (int_ n)
{
    /* call function body */
    return _di_c_up (6, (short) n);
}

__DOSCALL int_ _di_c_down (short, short);
static __inline int_ _dos_c_down (int_ n)
{
    /* call function body */
    return _di_c_down (7, (short) n);
}

__DOSCALL int_ _di_c_right (short, short);
static __inline int_ _dos_c_right (int_ n)
{
    /* call function body */
    return _di_c_right (8, (short) n);
}

__DOSCALL int_ _di_c_left (short, short);
static __inline int_ _dos_c_left (int_ n)
{
    /* call function body */
    return _di_c_left (9, (short) n);
}

__DOSCALL int_ _di_c_cls_ed (short, short);
static __inline int_ _dos_c_cls_ed (void_)
{
    /* call function body */
    return _di_c_cls_ed (10, 0);
}

__DOSCALL int_ _di_c_cls_st (short, short);
static __inline int_ _dos_c_cls_st (void_)
{
    /* call function body */
    return _di_c_cls_st (10, 1);
}

__DOSCALL int_ _di_c_cls_al (short, short);
static __inline int_ _dos_c_cls_al (void_)
{
    /* call function body */
    return _di_c_cls_al (10, 2);
}

__DOSCALL int_ _di_c_era_ed (short, short);
static __inline int_ _dos_c_era_ed (void_)
{
    /* call function body */
    return _di_c_era_ed (11, 0);
}

__DOSCALL int_ _di_c_era_st (short, short);
static __inline int_ _dos_c_era_st (void_)
{
    /* call function body */
    return _di_c_era_st (11, 1);
}

__DOSCALL int_ _di_c_era_al (short, short);
static __inline int_ _dos_c_era_al (void_)
{
    /* call function body */
    return _di_c_era_al (11, 2);
}

__DOSCALL int_ _di_c_ins (short, short);
static __inline int_ _dos_c_ins (int_ n)
{
    /* call function body */
    return _di_c_ins (12, (short) n);
}

__DOSCALL int_ _di_c_del (short, short);
static __inline int_ _dos_c_del (int_ n)
{
    /* call function body */
    return _di_c_del (13, (short) n);
}

__DOSCALL int_ _di_c_fnkmod (short, short);
static __inline int_ _dos_c_fnkmod (int_ n)
{
    /* call function body */
    return _di_c_fnkmod (14, (short) n);
}

__DOSCALL int_ _di_c_window (short, short, short);
static __inline int_ _dos_c_window (int_ ys, int_ yl)
{
    /* call function body */
    return _di_c_window (15, (short) ys, (short) yl);
}

__DOSCALL int_ _di_c_width (short, short);
static __inline int_ _dos_c_width (int_ n)
{
    /* call function body */
    return _di_c_width (16, (short) n);
}

__DOSCALL int_ _di_c_curon (short);
static __inline int_ _dos_c_curon (void_)
{
    /* call function body */
    return _di_c_curon (17);
}

__DOSCALL int_ _di_c_curoff (short);
static __inline int_ _dos_c_curoff (void_)
{
    /* call function body */
    return _di_c_curoff (18);
}

__DOSCALL int_ _di_k_keyinp (short);
static __inline int_ _dos_k_keyinp (void_)
{
    /* call function body */
    return _di_k_keyinp (0);
}

__DOSCALL int_ _di_k_keysns (short);
static __inline int_ _dos_k_keysns (void_)
{
    /* call function body */
    return _di_k_keysns (1);
}

__DOSCALL int_ _di_k_sftsns (short);
static __inline int_ _dos_k_sftsns (void_)
{
    /* call function body */
    return _di_k_sftsns (2);
}

__DOSCALL int_ _di_k_keybit (short, short);
static __inline int_ _dos_k_keybit (int_ n)
{
    /* call function body */
    return _di_k_keybit (3, (short) n);
}

__DOSCALL int_ _di_k_insmod (short, short);
static __inline void _dos_k_insmod (int_ n)
{
    /* call function body */
    (void) _di_k_insmod (4, (short) n);
}

__DOSCALL void *_di_intvcs (short, void *);
static __inline void *_dos_intvcs (int_ intno, void *jobadr)
{
    /* call function body */
    return _di_intvcs ((short) intno, jobadr);
}

__DOSCALL void _di_pspset (struct _psp *);
static __inline void _dos_pspset (struct _psp *pspadr)
{
    /* call function body */
    (void) _di_pspset (pspadr);
}

__DOSCALL int_ _di_gettim2 (void_);
static __inline int_ _dos_gettim2 (void_)
{
    /* call function body */
    return _di_gettim2 ();
}

__DOSCALL int_ _di_settim2 (long);
static __inline int_ _dos_settim2 (int_ time)
{
    /* call function body */
    return _di_settim2 ((long) time);
}

__DOSCALL int_ _di_namests (const char *, struct _namestbuf *);
static __inline int_ _dos_namests (const char *file, struct _namestbuf *buffer)
{
    /* call function body */
    return _di_namests (file, buffer);
}

__DOSCALL int_ _di_getdate (void_);
static __inline int_ _dos_getdate (void_)
{
    /* call function body */
    return _di_getdate ();
}

__DOSCALL int_ _di_setdate (short);
static __inline int_ _dos_setdate (int_ date)
{
    /* call function body */
    return _di_setdate ((short) date);
}

__DOSCALL int_ _di_gettime (void_);
static __inline int_ _dos_gettime (void_)
{
    /* call function body */
    return _di_gettime ();
}

__DOSCALL int_ _di_settime (short);
static __inline int_ _dos_settime (int_ time)
{
    /* call function body */
    return _di_settime ((short) time);
}

__DOSCALL void _di_verify (short);
static __inline void _dos_verify (int_ flag)
{
    /* call function body */
    (void) _di_verify ((short) flag);
}

__DOSCALL int_ _di_dup0 (short, short);
static __inline int_ _dos_dup0 (int_ fno, int_ newno)
{
    /* call function body */
    return _di_dup0 ((short) fno, (short) newno);
}

__DOSCALL int_ _di_vernum (void_);
static __inline int_ __const _dos_vernum (void_)
{
    /* call function body */
    return _di_vernum ();
}

__DOSCALL __volatile void _di_keeppr (long, short);
static __inline void __volatile _dos_keeppr (int_ prglen, int_ code)
{
    /* call function body */
    (void) _di_keeppr ((long) prglen, (short) code);
}

__DOSCALL int_ _di_getdpb (short, struct _dpbptr *);
static __inline int_ _dos_getdpb (int_ drive, struct _dpbptr *dpbptr)
{
    /* call function body */
    return _di_getdpb ((short) drive, dpbptr);
}

__DOSCALL int_ _di_breakck (short);
static __inline int_ _dos_breakck (int_ flag)
{
    /* call function body */
    return _di_breakck ((short) flag);
}

__DOSCALL void _di_drvxchg (short, short);
static __inline void _dos_drvxchg (int_ old_drv, int_ new_drv)
{
    /* call function body */
    (void) _di_drvxchg ((short) old_drv, (short) new_drv);
}

__DOSCALL void *_di_intvcg (short);
static __inline void *_dos_intvcg (int_ intno)
{
    /* call function body */
    return _di_intvcg ((short) intno);
}

__DOSCALL int_ _di_dskfre (short, struct _freeinf *);
static __inline int_ _dos_dskfre (int_ drive, struct _freeinf *buffer)
{
    /* call function body */
    return _di_dskfre ((short) drive, buffer);
}

__DOSCALL int_ _di_nameck (const char *, struct _nameckbuf *);
static __inline int_ _dos_nameck (const char *file, struct _nameckbuf *buffer)
{
    /* call function body */
    return _di_nameck (file, buffer);
}

__DOSCALL int_ _di_mkdir (const char *);
static __inline int_ _dos_mkdir (const char *file)
{
    /* call function body */
    return _di_mkdir (file);
}

__DOSCALL int_ _di_rmdir (const char *);
static __inline int_ _dos_rmdir (const char *file)
{
    /* call function body */
    return _di_rmdir (file);
}

__DOSCALL int_ _di_chdir (const char *);
static __inline int_ _dos_chdir (const char *file)
{
    /* call function body */
    return _di_chdir (file);
}

__DOSCALL int_ _di_create (const char *, short);
static __inline int_ _dos_create (const char *file, dosmode_t attr)
{
    /* call function body */
    return _di_create (file, (short) attr);
}

__DOSCALL int_ _di_open (const char *, short);
static __inline int_ _dos_open (const char *file, int_ mode)
{
    /* call function body */
    return _di_open (file, (short) mode);
}

__DOSCALL int_ _di_close (short);
static __inline int_ _dos_close (int_ fno)
{
    /* call function body */
    return _di_close ((short) fno);
}

__DOSCALL int_ _di_read (short, void *, long);
static __inline int_ _dos_read (int_ fno, char *buffer, int_ size)
{
    /* call function body */
    return _di_read ((short) fno, buffer, (long) size);
}

__DOSCALL int_ _di_write (short, const void *, long);
static __inline int_ _dos_write (int_ fno, const char *buffer, int_ size)
{
    /* call function body */
    return _di_write ((short) fno, buffer, (long) size);
}

__DOSCALL int_ _di_delete (const char *);
static __inline int_ _dos_delete (const char *file)
{
    /* call function body */
    return _di_delete (file);
}

__DOSCALL long _di_seek (short, long, short);
static __inline long _dos_seek (int_ fno, int_ offset, int_ mode)
{
    /* call function body */
    return _di_seek ((short) fno, (long) offset, (short) mode);
}

__DOSCALL int_ _di_chmod (const char *, short);
static __inline dosmode_t _dos_chmod (const char *file, dosmode_t attr)
{
    /* call function body */
    return _di_chmod (file, (short) attr);
}

__DOSCALL int_ _di_ioctrlgt (short, short);
static __inline int_ _dos_ioctrlgt (int_ fno)
{
    /* call function body */
    return _di_ioctrlgt (0, (short) fno);
}

__DOSCALL int_ _di_ioctrlst (short, short, short);
static __inline int_ _dos_ioctrlst (int_ fno, int_ data)
{
    /* call function body */
    return _di_ioctrlst (1, (short) fno, (short) data);
}

__DOSCALL int_ _di_ioctrlrh (short, short, char *, int_);
static __inline int_ _dos_ioctrlrh (int_ fno, char *buffer, int_ size)
{
    /* call function body */
    return _di_ioctrlrh (2, (short) fno, buffer, size);
}

__DOSCALL int_ _di_ioctrlwh (short, short, const char *, int_);
static __inline int_ _dos_ioctrlwh (int_ fno, const char *buffer, int_ size)
{
    /* call function body */
    return _di_ioctrlwh (3, (short) fno, buffer, size);
}

__DOSCALL int_ _di_ioctrlrd (short, short, char *, int_);
static __inline int_ _dos_ioctrlrd (int_ drive, char *buffer, int_ size)
{
    /* call function body */
    return _di_ioctrlrd (4, (short) drive, buffer, size);
}

__DOSCALL int_ _di_ioctrlwd (short, short, const char *, int_);
static __inline int_ _dos_ioctrlwd (int_ drive, const char *buffer, int_ size)
{
    /* call function body */
    return _di_ioctrlwd (5, (short) drive, buffer, size);
}

__DOSCALL int_ _di_ioctrlis (short, short);
static __inline int_ _dos_ioctrlis (int_ fno)
{
    /* call function body */
    return _di_ioctrlis (6, (short) fno);
}

__DOSCALL int_ _di_ioctrlos (short, short);
static __inline int_ _dos_ioctrlos (int_ fno)
{
    /* call function body */
    return _di_ioctrlos (7, (short) fno);
}

__DOSCALL int_ _di_ioctrldvgt (short, short);
static __inline int_ _dos_ioctrldvgt (int_ drive)
{
    /* call function body */
    return _di_ioctrldvgt (9, (short) drive);
}

__DOSCALL int_ _di_ioctrlfdgt (short, short);
static __inline int_ _dos_ioctrlfdgt (int_ fno)
{
    /* call function body */
    return _di_ioctrlfdgt (10, (short) fno);
}

__DOSCALL int_ _di_ioctrlrtset (short, short, short);
static __inline int_ _dos_ioctrlrtset (int_ count, int_ time)
{
    /* call function body */
    return _di_ioctrlrtset (11, (short) count, (short) time);
}

__DOSCALL int_ _di_ioctrldvctl (short, short, short, char *);
static __inline int_ _dos_ioctrldvctl (int_ drive, int_ f_code, char *buff)
{
    /* call function body */
    return _di_ioctrldvctl (12, (short) drive, (short) f_code, buff);
}

__DOSCALL int_ _di_ioctrlfdctl (short, short, short, char *);
static __inline int_ _dos_ioctrlfdctl (int_ fno, int_ f_code, char *buff)
{
    /* call function body */
    return _di_ioctrlfdctl (13, (short) fno, (short) f_code, buff);
}

__DOSCALL int_ _di_dup (short);
static __inline int_ _dos_dup (int_ fno)
{
    /* call function body */
    return _di_dup ((short) fno);
}

__DOSCALL int_ _di_dup2 (short, short);
static __inline int_ _dos_dup2 (int_ fno, int_ newno)
{
    /* call function body */
    return _di_dup2 ((short) fno, (short) newno);
}

__DOSCALL int_ _di_curdir (short, char *);
static __inline int_ _dos_curdir (int_ drive, char *buffer)
{
    /* call function body */
    return _di_curdir ((short) drive, buffer);
}

__DOSCALL void *_di_malloc (int_);
static __inline void *_dos_malloc (int_ size)
{
    /* call function body */
    return _di_malloc (size);
}

__DOSCALL int_ _di_mfree (void *);
static __inline int_ _dos_mfree (void *memptr)
{
    /* call function body */
    return _di_mfree (memptr);
}

__DOSCALL int_ _di_setblock (void *, int_);
static __inline int_ _dos_setblock (void *memptr, int_ newlen)
{
    /* call function body */
    return _di_setblock (memptr, newlen);
}

__DOSCALL void __volatile _di_exit2 (short);
static __inline void __volatile _dos_exit2 (int_ code)
{
    /* call function body */
    (void) _di_exit2 ((short) code);
}

__DOSCALL int_ _di_wait (void_);
static __inline int_ _dos_wait (void_)
{
    /* call function body */
    return _di_wait ();
}

__DOSCALL int_ _di_files (struct _filbuf *, const char *, short);
static __inline int_ _dos_files (struct _filbuf *buffer, const char *file, int_ attr)
{
    /* call function body */
    return _di_files (buffer, file, (short) attr);
}

__DOSCALL int_ _di_nfiles (struct _filbuf *);
static __inline int_ _dos_nfiles (struct _filbuf *buffer)
{
    /* call function body */
    return _di_nfiles (buffer);
}

__DOSCALL struct _psp *_di_setpdb (struct _psp *);
static __inline struct _psp *_dos_setpdb (struct _psp *pdbadr)
{
    /* call function body */
    return _di_setpdb (pdbadr);
}

__DOSCALL struct _psp *_di_getpdb (void_);
static __inline struct _psp *_dos_getpdb (void_)
{
    /* call function body */
    return _di_getpdb ();
}

__DOSCALL int_ _di_setenv (const char *, const char *, const char *);
static __inline int_ _dos_setenv (const char *name, const char *env, const char *buffer)
{
    /* call function body */
    return _di_setenv (name, env, buffer);
}

__DOSCALL int_ _di_getenv (const char *, const char *, char *);
static __inline int_ _dos_getenv (const char *name, const char *env, char *buffer)
{
    /* call function body */
    return _di_getenv (name, env, buffer);
}

__DOSCALL int_ _di_verifyg (void_);
static __inline int_ _dos_verifyg (void_)
{
    /* call function body */
    return _di_verifyg ();
}

__DOSCALL int_ _di_common_ck (short, const char *);
static __inline int_ _dos_common_ck (const char *name)
{
    /* call function body */
    return _di_common_ck (0, name);
}

__DOSCALL int_ _di_common_rd (short, const char *, int_, char *, int_);
static __inline int_ _dos_common_rd (const char *name, int_ pos, char *buffer, int_ len)
{
    /* call function body */
    return _di_common_rd (1, name, (short) pos, buffer, (short) len);
}

__DOSCALL int_ _di_common_wt (short, const char *, int_, const char *, int_);
static __inline int_ _dos_common_wt (const char *name, int_ pos, const char *buffer, int_ len)
{
    /* call function body */
    return _di_common_wt (2, name, (short) pos, buffer, (short) len);
}

__DOSCALL int_ _di_common_lk (short, const char *, int_, int_, int_);
static __inline int_ _dos_common_lk (const char *name, int_ pos, int_ id_psp, int_ len)
{
    /* call function body */
    return _di_common_lk (3, name, (short) pos, (short) id_psp, (short) len);
}

__DOSCALL int_ _di_common_fre (short, const char *, int_, int_, int_);
static __inline int_ _dos_common_fre (const char *name, int_ pos, int_ id_psp, int_ len)
{
    /* call function body */
    return _di_common_fre (4, name, (short) pos, (short) id_psp, (short) len);
}

__DOSCALL int_ _di_common_del (short, const char *);
static __inline int_ _dos_common_del (const char *name)
{
    /* call function body */
    return _di_common_del (5, name);
}

__DOSCALL int_ _di_move (const char *, const char *);
static __inline int_ _dos_move (const char *old_name, const char *new_name)
{
    /* call function body */
    return _di_move (old_name, new_name);
}

__DOSCALL int_ _di_rename (const char *, const char *);
static __inline int_ _dos_rename (const char *old_name, const char *new_name)
{
    /* call function body */
    return _di_rename (old_name, new_name);
}

__DOSCALL int_ _di_filedate (short, int_);
static __inline int_ _dos_filedate (int_ fno, int_ datetime)
{
    /* call function body */
    return _di_filedate ((short) fno, datetime);
}

__DOSCALL void *_di_malloc2 (short, int_);
static __inline void *_dos_malloc2 (int_ md, int_ size)
{
    /* call function body */
    return _di_malloc2 ((short) md, size);
}

__DOSCALL int_ _di_maketmp (const char *, short);
static __inline int_ _dos_maketmp (const char *file, int_ attr)
{
    /* call function body */
    return _di_maketmp (file, (short) attr);
}

__DOSCALL int_ _di_newfile (const char *, short);
static __inline int_ _dos_newfile (const char *file, dosmode_t attr)
{
    /* call function body */
    return _di_newfile (file, (short) attr);
}

__DOSCALL int_ _di_lock (short, short, int_, int_);
static __inline int_ _dos_lock (int_ fno, int_ offset, int_ len)
{
    /* call function body */
    return _di_lock (0, (short) fno, offset, len);
}

__DOSCALL int_ _di_unlock (short, short, int_, int_);
static __inline int_ _dos_unlock (int_ fno, int_ offset, int_ len)
{
    /* call function body */
    return _di_unlock (1, (short) fno, offset, len);
}

__DOSCALL int_ _di_getassign (short, const char *, char *);
static __inline int_ _dos_getassign (const char *path1, char *path2)
{
    /* call function body */
    return _di_getassign (0, path1, path2);
}

__DOSCALL int_ _di_makeassign (short, const char *, const char *, short);
static __inline int_ _dos_makeassign (const char *path1, const char *path2, int_ mode)
{
    /* call function body */
    return _di_makeassign (1, path1, path2, (short) mode);
}

__DOSCALL int_ _di_rassign (short, const char *);
static __inline int_ _dos_rassign (const char *path1)
{
    /* call function body */
    return _di_rassign (4, path1);
}

__DOSCALL union _fcb *_di_getfcb (short);
static __inline union _fcb *_dos_getfcb (unsigned int_ fno)
{
    /* call function body */
    return _di_getfcb ((short) fno);
}

__DOSCALL void *_di_s_malloc (short, int_);
static __inline void *_dos_s_malloc (int_ md, int_ size)
{
    /* call function body */
    return _di_s_malloc ((short) md, size);
}

__DOSCALL int_ _di_s_mfree (void *);
static __inline int_ _dos_s_mfree (void *memptr)
{
    /* call function body */
    return _di_s_mfree (memptr);
}

__DOSCALL int_ _di_s_process (short, int_, int_, int_);
static __inline int_ _dos_s_process (int_ tid, int_ start, int_ size, int_ i_len)
{
    /* call function body */
    return _di_s_process ((short) tid, start, size, i_len);
}

__DOSCALL void __volatile _di_retshell (void_);
static __inline void __volatile _dos_retshell (void_)
{
    /* call function body */
    (void) _di_retshell ();
}

__DOSCALL void __volatile _di_ctlabort (void_);
static __inline void __volatile _dos_ctlabort (void_)
{
    /* call function body */
    (void) _di_ctlabort ();
}

__DOSCALL void __volatile _di_errabort (void_);
static __inline void __volatile _dos_errabort (void_)
{
    /* call function body */
    (void) _di_errabort ();
}

__DOSCALL void _di_diskred (void *, short, short, short);
static __inline void _dos_diskred (void *addr, int_ drive, int_ sector, int_ seclen)
{
    /* call function body */
    (void) _di_diskred (addr, (short) drive, (short) sector, (short) seclen);
}

__DOSCALL void _di_diskred2 (void *, short, long, long);
static __inline void _dos_diskred2 (void *addr, int_ drive, int_ sector, int_ seclen)
{
    /* call function body */
    (void) _di_diskred2 ((void *) ((unsigned long) addr | (1 << 31)), (short) drive, (long) sector, (long) seclen);
}

__DOSCALL void _di_diskwrt (const void *, short, short, short);
static __inline void _dos_diskwrt (const void *addr, int_ drive, int_ sector, int_ seclen)
{
    /* call function body */
    (void) _di_diskwrt (addr, (short) drive, (short) sector, (short) seclen);
}

__DOSCALL void _di_diskwrt2 (const void *, short, long, long);
static __inline void _dos_diskwrt2 (const void *addr, int_ drive, int_ sector, int_ seclen)
{
    /* call function body */
    (void) _di_diskwrt2 ((void *) ((unsigned long) addr | (1 << 31)), (short) drive, (long) sector, (long) seclen);
}

__DOSCALL struct _indos *_di_indosflg (void_);
static __inline struct _indos *_dos_indosflg (void_)
{
    /* call function body */
    return _di_indosflg ();
}

__DOSCALL int_ _di_memcpy (void *, void *, short);
static __inline int_ _dos_memcpy (void *s_addr, void *d_addr, int_ mode)
{
    /* call function body */
    return _di_memcpy (s_addr, d_addr, (short) mode);
}

__DOSCALL int_ _di_open_pr (const char *, int_, int_, int_, short, int_, struct _prcctrl *, long);
static __inline int_ _dos_open_pr (const char *name, int_ counter, int_ usp, int_ ssp, int_ sr, int_ pc, struct _prcctrl *buff, long sleep_time)
{
    /* call function body */
    return _di_open_pr (name, counter, usp, ssp, (short) sr, pc, buff, (long) sleep_time);
}

__DOSCALL int_ _di_kill_pr (void_);
static __inline int_ _dos_kill_pr (void_)
{
    /* call function body */
    return _di_kill_pr ();
}

__DOSCALL int_ _di_get_pr (short, struct _prcptr *);
static __inline int_ _dos_get_pr (int_ tid, struct _prcptr *buff)
{
    /* call function body */
    return _di_get_pr ((short) tid, buff);
}

__DOSCALL int_ _di_suspend_pr (short);
static __inline int_ _dos_suspend_pr (int_ tid)
{
    /* call function body */
    return _di_suspend_pr ((short) tid);
}

__DOSCALL int_ _di_sleep_pr (long);
static __inline int_ _dos_sleep_pr (long time)
{
    /* call function body */
    return _di_sleep_pr (time);
}

__DOSCALL int_ _di_send_pr (short, short, short, char *, long);
static __inline int_ _dos_send_pr (int_ my_id, int_ your_id, int_ command, char *buff, long length)
{
    /* call function body */
    return _di_send_pr ((short) my_id, (short) your_id, (short) command, buff, length);
}

__DOSCALL long _di_time_pr (void_);
static __inline long _dos_time_pr (void_)
{
    /* call function body */
    return _di_time_pr ();
}

__DOSCALL void _di_change_pr (void_);
static __inline void _dos_change_pr (void_)
{
    /* call function body */
    (void) _di_change_pr ();
}

/*
** The following functions cannot be inline expanded. Please use library
** version instead.
*/

_EXTERN (int_ *_dos_importlnenv (void_));
_EXTERN (int_ _dos_lfiles (struct _filbuf *, const char *, int_));
_EXTERN (int_ _dos_link (const char *, const char *));
_EXTERN (int_ _dos_readlink (const char *, char *, int_));
_EXTERN (int_ _dos_symlink (const char *, const char *));
_EXTERN (int_ _dos_unlink (const char *));

/*
** If function name is one of _dos_super, SUPER, _iocs_b_super and B_SUPER,
** gcc adjusts stack (user/supervisor).
*/

__DOSCALL int_ _dos_super (long);

/*
** The following functions should be expanded with inline assembler because
** these functions are too complex for DOSCALL extensions.
*/

static __inline int_ _dos_exec2 (int_ md, const char *file, const char *p1, const char *p2)
{
    register int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d7/a3-a6,-(sp)\n\t"
		      "move.l %1,-(sp)\n\t"
		      "move.l %2,-(sp)\n\t"
		      "move.l %3,-(sp)\n\t"
		      "move.w %4,-(sp)\n\t"
		      "dc.w EXEC\n\t"
		      "lea.l 14(sp),sp\n\t"
		      "movem.l (sp)+,d3-d7/a3-a6"
			: "=d" (reg_d0)
			: "ri" ((int_) p2), "ri" ((int_) p1),
			  "ri" ((int_) file), "ri" ((short) md)
			: "d1", "d2", "a0", "a1", "a2");

    return reg_d0;
}

static __inline int_ _dos_loadexec (const char *file, const struct _comline *comline, const char *envptr)
{
    register int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d7/a3-a6,-(sp)\n\t"
		      "move.l %1,-(sp)\n\t"
		      "move.l %2,-(sp)\n\t"
		      "move.l %3,-(sp)\n\t"
		      "clr.w -(sp)\n\t"
		      "dc.w EXEC\n\t"
		      "lea.l 14(sp),sp\n\t"
		      "movem.l (sp)+,d3-d7/a3-a6"
			: "=d" (reg_d0)
			: "ri" ((int_) envptr), "ri" ((int_) comline),
			  "ri" ((int_) file)
			: "d1", "d2", "a0", "a1", "a2");

    return reg_d0;
}

static __inline int_ _dos_load (const char *file, const struct _comline *comline, const char *envptr)
{
    register int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d7/a3-a6,-(sp)\n\t"
		      "move.l %1,-(sp)\n\t"
		      "move.l %2,-(sp)\n\t"
		      "move.l %3,-(sp)\n\t"
		      "move.w #1,-(sp)\n\t"
		      "dc.w EXEC\n\t"
		      "lea.l 14(sp),sp\n\t"
		      "movem.l (sp)+,d3-d7/a3-a6"
			: "=d" (reg_d0)
			: "ri" ((int_) envptr), "ri" ((int_) comline),
			  "ri" ((int_) file)
			: "d1", "d2", "a0", "a1", "a2");

    return reg_d0;
}

static __inline int_ _dos_pathchk (const char *file, const struct _comline *comline, const char *envp)
{
    register int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,-(sp)\n\t"
		      "move.l %2,-(sp)\n\t"
		      "move.l %3,-(sp)\n\t"
		      "move.w #2,-(sp)\n\t"
		      "dc.w EXEC\n\t"
		      "lea.l 14(sp),sp"
			: "=d" (reg_d0)
			: "ri" ((int_) envp), "ri" ((int_) comline),
			  "ri" ((int_) file));

    return reg_d0;
}

static __inline int_ _dos_loadonly (const char *file, const void *loadadr, const void *limitadr)
{
    register int_ reg_d0 __asm ("d0");

    __asm __volatile ("move.l %1,-(sp)\n\t"
		      "move.l %2,-(sp)\n\t"
		      "move.l %3,-(sp)\n\t"
		      "move.w #3,-(sp)\n\t"
		      "dc.w EXEC\n\t"
		      "lea.l 14(sp),sp"
			: "=d" (reg_d0)
			: "ri" ((int_) limitadr), "ri" ((int_) loadadr),
			  "ri" ((int_) file));

    return reg_d0;
}

static __inline int_ _dos_execonly (void *jmpaddr)
{
    register int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d7/a3-a6,-(sp)\n\t"
		      "move.l %1,-(sp)\n\t"
		      "move.w #4,-(sp)\n\t"
		      "dc.w EXEC\n\t"
		      "addq.w #6,sp\n\t"
		      "movem.l (sp)+,d3-d7/a3-a6"
			: "=d" (reg_d0)
			: "ri" ((int_) jmpaddr)
			: "d1", "d2", "a0", "a1", "a2");

    return reg_d0;
}

static __inline int_ _dos_bindno (const char *file1, const char *file2)
{
    register int_ reg_d0 __asm ("d0");

    __asm __volatile ("movem.l d3-d7/a3-a6,-(sp)\n\t"
		      "clr.l -(sp)\n\t"
		      "move.l %1,-(sp)\n\t"
		      "move.l %2,-(sp)\n\t"
		      "move.w #5,-(sp)\n\t"
		      "dc.w EXEC\n\t"
		      "lea.l 14(sp),sp\n\t"
		      "movem.l (sp)+,d3-d7/a3-a6"
			: "=d" (reg_d0)
			: "ri" ((int_) file2), "ri" ((int_) file1)
			: "d1", "d2", "a0", "a1", "a2");

    return reg_d0;
}

static __inline void _dos_super_jsr (void (*func) (), struct _dregs *inregs, struct _dregs *outregs)
{
    __asm __volatile ("movem.l d0-d7/a0-a6,-(sp)\n\t"
		      "move.l %0,-(sp)\n\t"
		      "move.l %1,-(sp)\n\t"
		      "move.l %2,a0\n\t"
		      "movem.l (a0),d0-d7/a0-a6\n\t"
		      "dc.w SUPER_JSR\n\t"
		      "move.l a6,-(sp)\n\t"
		      "move.l 8(sp),a6\n\t"
		      "move.l (sp)+,56(a6)\n\t"
		      "addq.w #8,sp\n\t"
		      "movem.l d0-d7/a0-a5,(a6)\n\t"
		      "movem.l (sp)+,d0-d7/a0-a6"
			: /* no outputs */
			: "ri" ((int_) outregs), "ri" ((int_) func),
			  "ri" ((int_) inregs));
}

#endif
