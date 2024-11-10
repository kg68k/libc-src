/*
 * PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
 * --------------------------------------------------------------------
 * This file is written by the Project C Library Group,  and completely
 * in public domain. You can freely use, copy, modify, and redistribute
 * the whole contents, without this notice.
 * --------------------------------------------------------------------
 * based on the contribution by 大野博雄 (oo)
 * --------------------------------------------------------------------
 * $Id: rand48.c,v 1.1 1993/09/07 16:20:59 mura Exp $
 */

/*
** 線形合同アルゴリズム
**	xn = a*xn-1 + c
**	Default value a:0x5deecd66d, c:0xb
*/

/*
** 一つ疑問な点は、lrand48(), nrand48() で、負でない long 整数を返す
** とあるので、17bit シフトしている点です。上位の方から bit列を取り出
** すとあるのでこうしましたが...いいのかしら(^^;)
*/

/* Typedefs */
typedef long long int llint;

/* Macros */
#define us2lli(x, usp) \
    ((x) = ((llint) *(usp) << 32L) + ((llint) *(usp + 1) << 16L) + (llint) *(usp + 2))
#define lli2us(usp, x) \
    (*(usp) = ((x) >> 32L), *(usp + 1) = ((x) >> 16L), *(usp + 2) = (x))

/* File scope variables */
static llint a = 0x5deece66dLL;
static llint c = 0xbLL;
static llint xn = 0LL;

/* Functions */
double drand48 (void)
{
    /* 演算 */
    xn = a * xn + c;
    return (double) (xn & 0xffffffffffffLL) / (double) 0xffffffffffffLL;
}

/* Functions */
double erand48 (unsigned short seed[3])
{
    llint xi;

    /* 演算 */
    us2lli (xi, seed);
    xi = a * xi + c;
    lli2us (seed, xi);
    return (double) (xi & 0xffffffffffffLL) / (double) 0xffffffffffffLL;
}

/* Functions */
long lrand48 (void)
{
    /* 演算 */
    xn = a * xn + c;
    return (long) ((xn >> 17L) & 0x7fffffffL);
}

/* Functions */
long nrand48 (unsigned short seed[3])
{
    llint xi;

    /* 演算 */
    us2lli (xi, seed);
    xi = a * xi + c;
    lli2us (seed, xi);
    return (long) ((xi >> 17L) & 0x7fffffffL);
}

/* Functions */
long mrand48 (void)
{
    /* 演算 */
    xn = a * xn + c;
    return (long) ((xn >> 16L) & 0xffffffffU);
}

/* Functions */
long jrand48 (unsigned short seed[3])
{
    llint xi;

    /* 演算 */
    us2lli (xi, seed);
    xi = a * xi + c;
    lli2us (seed, xi);
    return (long) ((xi >> 16L) & 0xffffffffU);
}

/* Functions */
void srand48 (long seedval)
{
    /* 演算 */
    xn = (((llint) seedval) << 16L) + 0x330eLL;
    a = 0x5deece66dLL;
    c = 0xbLL;
}

/* Functions */
unsigned short *seed48 (unsigned short seed[3])
{
    static unsigned short myseed[3];

    /* 演算 */
    lli2us (myseed, xn);
    us2lli (xn, seed);
    a = 0x5deece66dLL;
    c = 0xbLL;
    return myseed;
}

/* Functions */
void lcong48 (unsigned short param[7])
{
    /* 演算 */
    us2lli (xn, param);
    us2lli (a, param + 3);
    c = (llint) param[6];
}
