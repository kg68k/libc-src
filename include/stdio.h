/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: stdio.h,v 1.11 1994/11/26 14:48:32 mura Exp $
 */

#ifndef __stdio_h__
#define __stdio_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __limits_h__
#include <limits.h>
#endif

#ifndef __va_list_defined__
#define __va_list_defined__
typedef char *va_list;
#endif

#ifndef __size_t_defined__
#define __size_t_defined__
typedef unsigned long size_t;
#endif

typedef long fpos_t;

typedef struct _stdbuf {	/* exactly 36bytes */
    int_ _cnt;
    int_ _bufsiz;
    int_ _flag;
    int_ _file;
    int_ _nback;
    unsigned char *_ptr;
    unsigned char *_base;
    unsigned char _pback[4];
    unsigned char _nbuff[4];
} FILE;

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define _IOFBF       0x0000
#define _IOLBF       0x0001
#define _IONBF       0x0002

#define _IOREAD      0x0004
#define _IOWRITE     0x0008
#define _IOAPPEND    0x0010
#define _IOTRUNC     0x0020
#define _IOCREAT     0x0040
#define _IOBIN       0x0080
#define _IOFREE      0x0100
#define _IOEOF       0x0200
#define _IOERR       0x0400
#define _IOR         0x0800
#define _IOW         0x1000
#define _IOAPPLS     0x2000
#define _IOEMU       0x4000

#define _IOUPD       (_IOREAD | _IOWRITE)
#define _IOBINARY    (_IOBIN)   /* for compatibility */
#define _IOTEXT      (0)        /* for compatibility */
#define _IOWRT       (_IOWRITE) /* for compatibility */
#define _IOMYBUF     (_IOFREE)  /* for compatibility */

#define SEEK_SET     0
#define SEEK_CUR     1
#define SEEK_END     2

#define BUFSIZ       4096
#define EOF          (-1)
#define FOPEN_MAX    OPEN_MAX
#define FILENAME_MAX PATH_MAX
#define L_tmpnam     PATH_MAX
#define L_ctermid    64
#define L_cuserid    64
#define P_tmpdir     "./"
#define TMP_MAX      456976

#define stdin       (&_iob[0])
#define stdout      (&_iob[1])
#define stderr      (&_iob[2])
#define stdaux      (&_iob[3])
#define stdprn      (&_iob[4])

extern struct _stdbuf _iob[];

_EXTERN (FILE *fdopen (int_, const char *));
_EXTERN (FILE *fopen (const char *, const char *));
_EXTERN (FILE *freopen (const char *, const char *, FILE *));
_EXTERN (FILE *popen (const char *, const char *));
_EXTERN (FILE *tmpfile (void_));
_EXTERN (char *fgets (char *, int_, FILE *));
_EXTERN (char *gets (char *));
_EXTERN (char *tempnam (const char *, const char *));
_EXTERN (char *tmpnam (char *));
_EXTERN (int_ eprintf (const char * dotdot_));
_EXTERN (int_ fclose (FILE *));
_EXTERN (int_ fcloseall (void_));
_EXTERN (int_ feof (FILE *));
_EXTERN (int_ ferror (FILE *));
_EXTERN (int_ fflush (FILE *));
_EXTERN (int_ fgetc (FILE *));
_EXTERN (int_ fgetpos (FILE *, fpos_t *));
_EXTERN (int_ fileno (FILE *));
_EXTERN (int_ flushall (void_));
_EXTERN (int_ fprintf (FILE *, const char * dotdot_));
_EXTERN (int_ fputc (int_, FILE *));
_EXTERN (int_ fputs (const char *, FILE *));
_EXTERN (int_ fscanf (FILE *, const char * dotdot_));
_EXTERN (int_ fseek (FILE *, long, int_));
_EXTERN (int_ fsetpos (FILE *, const fpos_t *));
_EXTERN (int_ getchar (void_));
_EXTERN (int_ getw (FILE *));
_EXTERN (int_ pclose (FILE *));
_EXTERN (int_ printf (const char * dotdot_));
_EXTERN (int_ putchar (int_));
_EXTERN (int_ puts (const char *));
_EXTERN (int_ putw (int_, FILE *));
_EXTERN (int_ remove (const char *));
_EXTERN (int_ rename (const char *, const char *));
_EXTERN (int_ scanf (const char * dotdot_));
_EXTERN (int_ setvbuf (FILE *, char *, int_, size_t));
_EXTERN (int_ sprintf (char *, const char * dotdot_));
_EXTERN (int_ sscanf (const char *, const char * dotdot_));
_EXTERN (int_ ungetc (int_, FILE *));
_EXTERN (int_ vfprintf (FILE *, const char *, va_list));
_EXTERN (int_ vfscanf (FILE *, const char *, va_list));
_EXTERN (int_ vprintf (const char *, va_list));
_EXTERN (int_ vscanf (const char *, va_list));
_EXTERN (int_ vsprintf (char *, const char *, va_list));
_EXTERN (int_ vsscanf (const char *, const char *, va_list));
_EXTERN (long ftell (FILE *));
_EXTERN (size_t fread (void *, size_t, size_t, FILE *));
_EXTERN (size_t fwrite (const void *, size_t, size_t, FILE *));
_EXTERN (void clearerr (FILE *));
_EXTERN (void fmallocmap (FILE *));
_EXTERN (void fmode (FILE *, int_));
_EXTERN (void perror (const char *));
_EXTERN (void rewind (FILE *));
_EXTERN (void setbuf (FILE *, char *));

#ifdef __NO_STDIO_INLINE__

#define getc fgetc
#define putc fputc

#else

#define getc(fp) \
    (--(fp)->_cnt >= 0 ? ((int_) *(fp)->_ptr++) : fgetc (fp))

#define putc(c, fp) \
    (--(fp)->_cnt >= 0 ? ((int_) *(fp)->_ptr++ = (c)) : fputc ((c), (fp)))

#define feof(fp)   ((fp)->_flag & _IOEOF)
#define ferror(fp) ((fp)->_flag & _IOERR)
#define fileno(fp) ((fp)->_file)
#define getchar()  (fgetc (stdin))
#define putchar(c) (fputc ((c), stdout))

#endif

#endif
