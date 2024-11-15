/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: dos_p.h,v 1.3 1993/10/06 16:46:07 mura Exp $
 */

#ifndef __sys_dos_p_h__
#define __sys_dos_p_h__

_EXTERN (dosmode_t _dos_chmod (const char *, dosmode_t));
_EXTERN (int_ __const _dos_vernum (void_));
_EXTERN (int_ _dos_bindno (const char *, const char *));
_EXTERN (int_ _dos_breakck (int_));
_EXTERN (int_ _dos_c_cls_al (void_));
_EXTERN (int_ _dos_c_cls_ed (void_));
_EXTERN (int_ _dos_c_cls_st (void_));
_EXTERN (int_ _dos_c_color (int_));
_EXTERN (int_ _dos_c_curoff (void_));
_EXTERN (int_ _dos_c_curon (void_));
_EXTERN (int_ _dos_c_del (int_));
_EXTERN (int_ _dos_c_down (int_));
_EXTERN (int_ _dos_c_down_s (void_));
_EXTERN (int_ _dos_c_era_al (void_));
_EXTERN (int_ _dos_c_era_ed (void_));
_EXTERN (int_ _dos_c_era_st (void_));
_EXTERN (int_ _dos_c_fnkmod (int_));
_EXTERN (int_ _dos_c_ins (int_));
_EXTERN (int_ _dos_c_left (int_));
_EXTERN (int_ _dos_c_locate (int_, int_));
_EXTERN (int_ _dos_c_print (const char *));
_EXTERN (int_ _dos_c_putc (int_));
_EXTERN (int_ _dos_c_right (int_));
_EXTERN (int_ _dos_c_up (int_));
_EXTERN (int_ _dos_c_up_s (void_));
_EXTERN (int_ _dos_c_width (int_));
_EXTERN (int_ _dos_c_window (int_, int_));
_EXTERN (int_ _dos_chdir (const char *));
_EXTERN (int_ _dos_chgdrv (int_));
_EXTERN (int_ _dos_cinsns (void_));
_EXTERN (int_ _dos_close (int_));
_EXTERN (int_ _dos_cominp (void_));
_EXTERN (int_ _dos_common_ck (const char *));
_EXTERN (int_ _dos_common_del (const char *));
_EXTERN (int_ _dos_common_fre (const char *, int_, int_, int_));
_EXTERN (int_ _dos_common_lk (const char *, int_, int_, int_));
_EXTERN (int_ _dos_common_rd (const char *, int_, char *, int_));
_EXTERN (int_ _dos_common_wt (const char *, int_, const char *, int_));
_EXTERN (int_ _dos_consns (void_));
_EXTERN (int_ _dos_coutsns (void_));
_EXTERN (int_ _dos_create (const char *, dosmode_t));
_EXTERN (int_ _dos_curdir (int_, char *));
_EXTERN (int_ _dos_curdrv (void_));
_EXTERN (int_ _dos_delete (const char *));
_EXTERN (int_ _dos_drvctrl (int_, int_));
_EXTERN (int_ _dos_dskfre (int_, struct _freeinf *));
_EXTERN (int_ _dos_dup (int_));
_EXTERN (int_ _dos_dup0 (int_, int_));
_EXTERN (int_ _dos_dup2 (int_, int_));
_EXTERN (int_ _dos_exec2 (int_, const char *, const char *, const char *));
_EXTERN (int_ _dos_execonly (void *));
_EXTERN (int_ _dos_fatchk (const char *, unsigned short *));
_EXTERN (int_ _dos_fatchk2 (const char *, unsigned short *, int_));
_EXTERN (int_ _dos_fgetc (int_));
_EXTERN (int_ _dos_fgets (struct _inpptr *, int_));
_EXTERN (int_ _dos_filedate (int_, int_));
_EXTERN (int_ _dos_files (struct _filbuf *, const char *, int_));
_EXTERN (int_ _dos_get_pr (int_, struct _prcptr *));
_EXTERN (int_ _dos_getassign (const char *, char *));
_EXTERN (int_ _dos_getc (void_));
_EXTERN (int_ _dos_getchar (void_));
_EXTERN (int_ _dos_getdate (void_));
_EXTERN (int_ _dos_getdpb (int_, struct _dpbptr *));
_EXTERN (int_ _dos_getenv (const char *, const char *, char *));
_EXTERN (int_ _dos_gets (struct _inpptr *));
_EXTERN (int_ _dos_getss (struct _inpptr *));
_EXTERN (int_ _dos_gettim2 (void_));
_EXTERN (int_ _dos_gettime (void_));
_EXTERN (int_ _dos_hendspio (void_));
_EXTERN (int_ _dos_hendspip (int_, const char *));
_EXTERN (int_ _dos_hendspir (int_, const char *));
_EXTERN (int_ _dos_hendspmo (void_));
_EXTERN (int_ _dos_hendspmp (int_, const char *));
_EXTERN (int_ _dos_hendspmr (int_, const char *));
_EXTERN (int_ _dos_hendspso (void_));
_EXTERN (int_ _dos_hendspsp (int_, const char *));
_EXTERN (int_ _dos_hendspsr (int_, const char *));
_EXTERN (int_ _dos_inkey (void_));
_EXTERN (int_ _dos_inpout (int_));
_EXTERN (int_ _dos_ioctrldvctl (int_, int_, char *));
_EXTERN (int_ _dos_ioctrldvgt (int_));
_EXTERN (int_ _dos_ioctrlfdctl (int_, int_, char *));
_EXTERN (int_ _dos_ioctrlfdgt (int_));
_EXTERN (int_ _dos_ioctrlgt (int_));
_EXTERN (int_ _dos_ioctrlis (int_));
_EXTERN (int_ _dos_ioctrlos (int_));
_EXTERN (int_ _dos_ioctrlrd (int_, char *, int_));
_EXTERN (int_ _dos_ioctrlrh (int_, char *, int_));
_EXTERN (int_ _dos_ioctrlrtset (int_, int_));
_EXTERN (int_ _dos_ioctrlst (int_, int_));
_EXTERN (int_ _dos_ioctrlwd (int_, const char *, int_));
_EXTERN (int_ _dos_ioctrlwh (int_, const char *, int_));
_EXTERN (int_ _dos_k_keybit (int_));
_EXTERN (int_ _dos_k_keyinp (void_));
_EXTERN (int_ _dos_k_keysns (void_));
_EXTERN (int_ _dos_k_sftsns (void_));
_EXTERN (int_ _dos_keysns (void_));
_EXTERN (int_ _dos_kflushgc (void_));
_EXTERN (int_ _dos_kflushgp (void_));
_EXTERN (int_ _dos_kflushgs (struct _inpptr *));
_EXTERN (int_ _dos_kflushin (void_));
_EXTERN (int_ _dos_kflushio (int_));
_EXTERN (int_ _dos_kill_pr (void_));
_EXTERN (int_ _dos_load (const char *, const struct _comline *, const char *));
_EXTERN (int_ _dos_loadexec (const char *, const struct _comline *, const char *));
_EXTERN (int_ _dos_loadonly (const char *, const void *, const void *));
_EXTERN (int_ _dos_lock (int_, int_, int_));
_EXTERN (int_ _dos_makeassign (const char *, const char *, int_));
_EXTERN (int_ _dos_maketmp (const char *, int_));
_EXTERN (int_ _dos_memcpy (void *, void *, int_));
_EXTERN (int_ _dos_mfree (void *));
_EXTERN (int_ _dos_mkdir (const char *));
_EXTERN (int_ _dos_move (const char *, const char *));
_EXTERN (int_ _dos_nameck (const char *, struct _nameckbuf *));
_EXTERN (int_ _dos_namests (const char *, struct _namestbuf *));
_EXTERN (int_ _dos_newfile (const char *, dosmode_t));
_EXTERN (int_ _dos_nfiles (struct _filbuf *));
_EXTERN (int_ _dos_open (const char *, int_));
_EXTERN (int_ _dos_open_pr (const char *, int_, int_, int_, int_, int_, struct _prcctrl *, long));
_EXTERN (int_ _dos_pathchk (const char *, const struct _comline *, const char *));
_EXTERN (int_ _dos_prnsns (void_));
_EXTERN (int_ _dos_rassign (const char *));
_EXTERN (int_ _dos_read (int_, char *, int_));
_EXTERN (int_ _dos_rename (const char *, const char *));
_EXTERN (int_ _dos_rmdir (const char *));
_EXTERN (int_ _dos_s_mfree (void *));
_EXTERN (int_ _dos_s_process (int_, int_, int_, int_));
_EXTERN (int_ _dos_send_pr (int_, int_, int_, char *, long));
_EXTERN (int_ _dos_setblock (void *, int_));
_EXTERN (int_ _dos_setdate (int_));
_EXTERN (int_ _dos_setenv (const char *, const char *, const char *));
_EXTERN (int_ _dos_settim2 (int_));
_EXTERN (int_ _dos_settime (int_));
_EXTERN (int_ _dos_sleep_pr (long));
_EXTERN (int_ _dos_super (int_));
_EXTERN (int_ _dos_suspend_pr (int_));
_EXTERN (int_ _dos_unlock (int_, int_, int_));
_EXTERN (int_ _dos_verifyg (void_));
_EXTERN (int_ _dos_wait (void_));
_EXTERN (int_ _dos_write (int_, const char *, int_));
_EXTERN (long _dos_seek (int_, int_, int_));
_EXTERN (long _dos_time_pr (void_));
_EXTERN (struct _indos *_dos_indosflg (void_));
_EXTERN (struct _psp *_dos_getpdb (void_));
_EXTERN (struct _psp *_dos_setpdb (struct _psp *));
_EXTERN (union _fcb *_dos_getfcb (unsigned int_));
_EXTERN (void *_dos_intvcg (int_));
_EXTERN (void *_dos_intvcs (int_, void *));
_EXTERN (void *_dos_malloc (int_));
_EXTERN (void *_dos_malloc2 (int_, int_));
_EXTERN (void *_dos_s_malloc (int_, int_));
_EXTERN (void __volatile _dos_ctlabort (void_));
_EXTERN (void __volatile _dos_errabort (void_));
_EXTERN (void __volatile _dos_exit (void_));
_EXTERN (void __volatile _dos_exit2 (int_));
_EXTERN (void __volatile _dos_keeppr (int_, int_));
_EXTERN (void __volatile _dos_retshell (void_));
_EXTERN (void _dos_allclose (void_));
_EXTERN (void _dos_change_pr (void_));
_EXTERN (void _dos_comout (int_));
_EXTERN (void _dos_diskred (void *, int_, int_, int_));
_EXTERN (void _dos_diskred2 (void *, int_, int_, int_));
_EXTERN (void _dos_diskwrt (const void *, int_, int_, int_));
_EXTERN (void _dos_diskwrt2 (const void *, int_, int_, int_));
_EXTERN (void _dos_drvxchg (int_, int_));
_EXTERN (void _dos_fflush (void_));
_EXTERN (void _dos_fnckeygt (int_, char *));
_EXTERN (void _dos_fnckeyst (int_, const char *));
_EXTERN (void _dos_fputc (int_, int_));
_EXTERN (void _dos_fputs (const char *, int_));
_EXTERN (void _dos_hendspic (int_));
_EXTERN (void _dos_hendspmc (void_));
_EXTERN (void _dos_hendspsc (void_));
_EXTERN (void _dos_k_insmod (int_));
_EXTERN (void _dos_print (const char *));
_EXTERN (void _dos_prnout (int_));
_EXTERN (void _dos_pspset (struct _psp *));
_EXTERN (void _dos_putchar (int_));
_EXTERN (void _dos_super_jsr (void (*) (), struct _dregs *, struct _dregs *));
_EXTERN (void _dos_verify (int_));

/* The following functions are symblic link emulation routines */

_EXTERN (int_ *_dos_importlnenv (void_));
_EXTERN (int_ _dos_lfiles (struct _filbuf *, const char *, int_));
_EXTERN (int_ _dos_link (const char *, const char *));
_EXTERN (int_ _dos_readlink (const char *, char *, int_));
_EXTERN (int_ _dos_symlink (const char *, const char *));
_EXTERN (int_ _dos_unlink (const char *));

#endif
