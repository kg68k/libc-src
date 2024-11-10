/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: iocs.h,v 1.1.1.1 1993/04/18 16:14:27 mura Exp $
 */

#ifndef __sys_iocs_h__
#define __sys_iocs_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

struct _boxptr {
    short x1;
    short y1;
    short x2;
    short y2;
    unsigned short color;
    unsigned short linestyle;
};

struct _circleptr {
    short x;
    short y;
    unsigned short radius;
    unsigned short color;
    short start;
    short end;
    unsigned short ratio;
};

struct _fillptr {
    short x1;
    short y1;
    short x2;
    short y2;
    unsigned short color;
};

struct _fntbuf {
    short xl;
    short yl;
    unsigned char buffer[72];
};

struct _getptr {
    short x1;
    short y1;
    short x2;
    short y2;
    void *buf_start;
    void *buf_end;
};

struct _lineptr {
    short x1;
    short y1;
    short x2;
    short y2;
    unsigned short color;
    unsigned short linestyle;
};

struct _paintptr {
    short x;
    short y;
    unsigned short color;
    void *buf_start;
    void *buf_end;
};

struct _pointptr {
    short x;
    short y;
    unsigned short color;
};

struct _psetptr {
    short x;
    short y;
    unsigned short color;
};

struct _putptr {
    short x1;
    short y1;
    short x2;
    short y2;
    const void *buf_start;
    const void *buf_end;
};

struct _symbolptr {
    short x1;
    short y1;
    unsigned char *string_address;
    unsigned char mag_x;
    unsigned char mag_y;
    unsigned short color;
    unsigned char font_type;
    unsigned char angle;
};

struct _regs {
    int_ d0;
    int_ d1;
    int_ d2;
    int_ d3;
    int_ d4;
    int_ d5;
    int_ d6;
    int_ d7;
    int_ a1;
    int_ a2;
    int_ a3;
    int_ a4;
    int_ a5;
    int_ a6;
};

struct _chain {
    void *addr;
    unsigned short len;
};

struct _chain2 {
    void *addr;
    unsigned short len;
    const struct _chain2 *next;
};

struct _clipxy {
    short xs;
    short ys;
    short xe;
    short ye;
};

struct _patst {
    short offsetx;
    short offsety;
    short shadow[16];
    short pattern[16];
};

struct _tboxptr {
    unsigned short vram_page;
    short x;
    short y;
    short x1;
    short y1;
    unsigned short line_style;
};

struct _txfillptr {
    unsigned short vram_page;
    short x;
    short y;
    short x1;
    short y1;
    unsigned short fill_patn;
};

struct _trevptr {
    unsigned short vram_page;
    short x;
    short y;
    short x1;
    short y1;
};

struct _xlineptr {
    unsigned short vram_page;
    short x;
    short y;
    short x1;
    unsigned short line_style;
};

struct _ylineptr {
    unsigned short vram_page;
    short x;
    short y;
    short y1;
    unsigned short line_style;
};

/*
** If you want to use other inline headers, please add your selection
** mechanism here...
*/

#ifdef __IOCS_INLINE__
#include <sys/iocs_i.h>
#else
#include <sys/iocs_p.h>
#endif

#endif
