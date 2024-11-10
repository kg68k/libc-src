/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: poll.h,v 1.2 1993/10/06 16:44:38 mura Exp $
 */

/*
** PLEASE DO NOT USE THIS HEADER FILE !!!
** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
** The following features will be supported in the long long
** future,  but not supprted now.   If you want to use these
** features, please make the following interfaces, and contribute
** them to us.
*/

#ifndef __poll_h__
#define __poll_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#define POLLNORM 1
#define POLLOUT  2
#define POLLERR  3
#define POLLHUP  4
#define POLLNVAL 5

struct pollfd {
    int_ fd;
    int_ events;
    int_ revents;
};

_EXTERN (int_ poll (struct pollfd [], unsigned int_, int_));

#endif
