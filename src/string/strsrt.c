/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution by TomY.
 * --------------------------------------------------------------------
 * $Id: strsrt.c,v 1.2 1993/09/07 16:22:13 mura Exp $
 */

/* System headers */
#include <stdlib.h>
#include <string.h>

/* Local Functions */
static int string_compare (const void *p1, const void *p2)
{
    /* void ポインタは char ** を指している */
    return strcmp (* (const char **) p1, * (const char **) p2);
}

/* Functions */
void strsrt (char **string, int num)
{
    /* 比較関数 string_compare を使ってソート */
    qsort (string, num, sizeof (char *), string_compare);
}
