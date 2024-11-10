/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: termios.h,v 1.2 1993/10/06 16:45:14 mura Exp $
 */

/*
** PLEASE DO NOT USE THIS HEADER FILE !!!
** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
** The following features will be supported in the long long
** future,  but not supprted now.   If you want to use these
** features, please make the following interfaces, and contribute
** them to us.
*/

#ifndef __termios_h__
#define __termios_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define NCCS 9

typedef char cc_t;
typedef int_ speed_t;
typedef unsigned int_ tcflag_t;

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_cc[NCCS];
};

#define BRKINT 0x0001
#define ICRNL  0x0002
#define IGNBRK 0x0004
#define IGNCR  0x0008
#define IGNPAR 0x0010
#define INLCR  0x0020
#define INPCK  0x0040
#define ISTRIP 0x0080
#define IUCLC  0x0100
#define IXANY  0x0200
#define IXOFF  0x0400
#define IXON   0x0800
#define PARMRK 0x1000

#define OPOST  0x00000001
#define OLCUC  0x00000002
#define ONLCR  0x00000004
#define OCRNL  0x00000008
#define ONOCR  0x00000010
#define ONLRET 0x00000020
#define OFILL  0x00000040
#define OFDEL  0x00000080
#define NLDLY  0x00000100
#define NL0    0x00000200
#define NL1    0x00000400
#define CRDLY  0x00000800
#define CR0    0x00001000
#define CR1    0x00002000
#define CR2    0x00004000
#define CR3    0x00008000
#define TABDLY 0x00010000
#define TAB0   0x00020000
#define TAB1   0x00040000
#define TAB2   0x00080000
#define TAB3   0x00100000
#define BSDLY  0x00200000
#define BS0    0x00400000
#define BS1    0x00800000
#define VTDLY  0x01000000
#define VT0    0x02000000
#define VT1    0x04000000
#define FFDLY  0x08000000
#define FF0    0x10000000
#define FF1    0x20000000

#define CSIZE  0x0001
#define CS5    0x0002
#define CS6    0x0004
#define CS7    0x0008
#define CS8    0x0010
#define CSTOPB 0x0020
#define CREAD  0x0040
#define PARENB 0x0080
#define PARODD 0x0100
#define HUPCL  0x0200
#define CLOCAL 0x0400

#define ECHO   0x0001
#define ECHOE  0x0002
#define ECHOK  0x0004
#define ECHONL 0x0008
#define ICANON 0x0010
#define IEXTEN 0x0020
#define ISIG   0x0040
#define NOFLSH 0x0080
#define TOSTOP 0x0100
#define XCASE  0x0200

#define VEOF   0
#define VEOL   1
#define VERASE 2
#define VINTR  3
#define VKILL  4
#define VQUIT  5
#define VSTART 6
#define VSTOP  7
#define VSUSP  8
#define VMIN   0 /* = VEOF */
#define VTIME  1 /* = VEOL */

#define B0      0
#define B50     1
#define B75     2
#define B110    3
#define B134    4
#define B150    5
#define B200    6
#define B300    7
#define B600    8
#define B1200   9
#define B1800  10
#define B2400  11
#define B4800  12
#define B9600  13
#define B19200 14
#define B38400 15

#define TCSANOW   0
#define TCSADRAIN 1
#define TCSAFLUSH 2

#define TCIFLUSH  0x01
#define TCOFLUSH  0x02
#define TCIOFLUSH (TCIFLUSH | TCOFLUSH)

#define TCIOFF 0
#define TCION  1
#define TCOOFF 2
#define TCOON  3

_EXTERN (int_ cfsetispeed (struct termios *, speed_t));
_EXTERN (int_ cfsetospeed (struct termios *, speed_t));
_EXTERN (int_ tcdrain (int_));
_EXTERN (int_ tcflow (int_, int_));
_EXTERN (int_ tcflush (int_, int_));
_EXTERN (int_ tcgetattr (int_, struct termios *));
_EXTERN (int_ tcsendbreak (int_, int_));
_EXTERN (int_ tcsetattr (int_, int_, struct termios *));
_EXTERN (speed_t cfgetispeed (struct termios *));
_EXTERN (speed_t cfgetospeed (struct termios *));

#endif
