/*
** test_conv.c — unit tests for libft conversion category.
**
** Edge cases covered (D-03 matrix):
**   ft_atoi: positive, negative, zero, leading whitespace, sign-only, NULL
**   ft_itoa: positive, negative, zero, INT_MIN, allocation sanity
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "../../include/libft.h"

static int g_fails = 0;

#define ASSERT(cond, label) \
    do { \
        if (cond) { printf("[PASS] %s\n", label); } \
        else       { printf("[FAIL] %s\n", label); g_fails++; } \
    } while (0)

/* ─── ft_atoi ────────────────────────────────────────────────────────────── */

static void test_atoi(void)
{
    ASSERT(ft_atoi("42")        == 42,   "atoi: '42'");
    ASSERT(ft_atoi("-7")        == -7,   "atoi: '-7'");
    ASSERT(ft_atoi("0")         == 0,    "atoi: '0'");
    ASSERT(ft_atoi("   42")     == 42,   "atoi: leading spaces");
    ASSERT(ft_atoi("\t\n  -3")  == -3,   "atoi: mixed whitespace + negative");
    ASSERT(ft_atoi("+5")        == 5,    "atoi: explicit plus sign");
    ASSERT(ft_atoi("99abc")     == 99,   "atoi: stops at non-digit");
    ASSERT(ft_atoi("abc")       == 0,    "atoi: no leading digit → 0");
    ASSERT(ft_atoi(NULL)        == 0,    "atoi: NULL → 0");
}

/* ─── ft_itoa ────────────────────────────────────────────────────────────── */

static void test_itoa(void)
{
    char *s;

    s = ft_itoa(0);
    ASSERT(s && strcmp(s, "0") == 0,    "itoa: 0");
    free(s);

    s = ft_itoa(42);
    ASSERT(s && strcmp(s, "42") == 0,   "itoa: 42");
    free(s);

    s = ft_itoa(-7);
    ASSERT(s && strcmp(s, "-7") == 0,   "itoa: -7");
    free(s);

    s = ft_itoa(INT_MAX);
    ASSERT(s && strcmp(s, "2147483647") == 0, "itoa: INT_MAX");
    free(s);

    s = ft_itoa(INT_MIN);
    ASSERT(s && strcmp(s, "-2147483648") == 0, "itoa: INT_MIN");
    free(s);
}

/* ─── main ───────────────────────────────────────────────────────────────── */

int main(void)
{
    printf("\n=== test_conv ===\n");
    test_atoi();
    test_itoa();
    printf("\n%s — %d failure(s)\n", g_fails == 0 ? "ALL PASS" : "SOME FAIL", g_fails);
    return (g_fails != 0);
}
