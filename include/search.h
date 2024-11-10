/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * $Id: search.h,v 1.2 1993/10/06 16:44:50 mura Exp $
 */

/*
** PLEASE DO NOT USE THIS HEADER FILE !!!
** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
** The following features will be supported in future, but not
** supprted now.  If you want to use the features, please make
** the following interfaces, and contribute them to us.
*/

#ifndef __search_h__
#define __search_h__

#ifndef __cdecl_h__
#include <cdecl.h>
#endif

#ifndef __sys_types_h__
#include <sys/types.h>
#endif

typedef enum {
    FIND,
    ENTER,
} ACTION;

typedef enum {
    preorder,
    postorder,
    endorder,
    leaf,
} VISIT;

typedef struct {
    char *key;
    char *data;
} ENTRY;

_EXTERN (ENTRY *hsearch (ENTRY, ACTION));
_EXTERN (int_ hcreate (unsigned int_));
_EXTERN (void *bsearch (const void *, const void *, size_t, size_t, int_ (*) (const void *, const void *)));
_EXTERN (void *lfind (const void *, const void *, size_t *, size_t, int_ (*) (const void *, const void *)));
_EXTERN (void *lsearch (const void *, const void *, size_t *, size_t, int_ (*) (const void *, const void *)));
_EXTERN (void *tdelete (const void *, const void **, int_ (*) (const void *, const void *)));
_EXTERN (void *tfind (const void *, const void **, int_ (*) (const void *, const void *)));
_EXTERN (void *tsearch (const void *, const void **, int_ (*) (const void *, const void *)));
_EXTERN (void hdestroy (void_));
_EXTERN (void twalk (const void **, void (*) (const void *, const VISIT, const int_)));

#endif
