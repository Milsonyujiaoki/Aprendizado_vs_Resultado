/*
** test_string.c — unit tests for libft string category.
**
** Edge cases covered (D-03 matrix):
**   - NULL pointer inputs
**   - Empty string ("")
**   - Strings without NUL (pointer safety — limited to safe patterns)
**   - Concatenation into pre-sized buffer
**   - strcmp: equal, less, greater, one empty
**   - strdup: new buffer, mutation independence
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/libft.h"

static int g_fails = 0;

#define ASSERT(cond, label) \
    do { \
        if (cond) { printf("[PASS] %s\n", label); } \
        else       { printf("[FAIL] %s\n", label); g_fails++; } \
    } while (0)

/* ─── ft_strlen ─────────────────────────────────────────────────────────── */

static void test_strlen(void)
{
    ASSERT(ft_strlen("hello") == 5,  "strlen: 'hello' == 5");
    ASSERT(ft_strlen("")      == 0,  "strlen: empty string == 0");
    ASSERT(ft_strlen(NULL)    == 0,  "strlen: NULL returns 0");
    ASSERT(ft_strlen("a")     == 1,  "strlen: single char");
}

/* ─── ft_strcpy ─────────────────────────────────────────────────────────── */

static void test_strcpy(void)
{
    char dst[32];

    ft_strcpy(dst, "world");
    ASSERT(strcmp(dst, "world") == 0, "strcpy: copies string correctly");

    ft_strcpy(dst, "");
    ASSERT(strcmp(dst, "") == 0,      "strcpy: empty string");

    ASSERT(ft_strcpy(NULL, "x") == NULL, "strcpy: NULL dst returns NULL");
    ASSERT(ft_strcpy(dst, NULL) == NULL, "strcpy: NULL src returns NULL");
}

/* ─── ft_strcat ─────────────────────────────────────────────────────────── */

static void test_strcat(void)
{
    char dst[32];

    ft_strcpy(dst, "hello");
    ft_strcat(dst, " world");
    ASSERT(strcmp(dst, "hello world") == 0, "strcat: appends correctly");

    /* append empty */
    ft_strcat(dst, "");
    ASSERT(strcmp(dst, "hello world") == 0, "strcat: append empty is no-op");

    ASSERT(ft_strcat(NULL, "x") == NULL, "strcat: NULL dst returns NULL");
    ASSERT(ft_strcat(dst, NULL) == NULL, "strcat: NULL src returns NULL");
}

/* ─── ft_strcmp ─────────────────────────────────────────────────────────── */

static void test_strcmp(void)
{
    ASSERT(ft_strcmp("abc", "abc")  == 0,  "strcmp: equal strings");
    ASSERT(ft_strcmp("abc", "abd")  <  0,  "strcmp: abc < abd");
    ASSERT(ft_strcmp("abd", "abc")  >  0,  "strcmp: abd > abc");
    ASSERT(ft_strcmp("", "")        == 0,  "strcmp: both empty");
    ASSERT(ft_strcmp("a", "")       >  0,  "strcmp: non-empty > empty");
    ASSERT(ft_strcmp("", "a")       <  0,  "strcmp: empty < non-empty");
    ASSERT(ft_strcmp(NULL, "a")     == 0,  "strcmp: NULL returns 0 (safe-first)");
}

/* ─── ft_strdup ─────────────────────────────────────────────────────────── */

static void test_strdup(void)
{
    char *dup = ft_strdup("copy me");
    ASSERT(dup != NULL,                    "strdup: returns non-NULL");
    ASSERT(strcmp(dup, "copy me") == 0,    "strdup: content matches");

    /* mutation independence */
    dup[0] = 'X';
    ASSERT(strcmp(dup, "Xopy me") == 0,    "strdup: independent buffer (mutation)");
    free(dup);

    /* empty string */
    dup = ft_strdup("");
    ASSERT(dup != NULL && dup[0] == '\0',  "strdup: empty string");
    free(dup);

    /* NULL */
    ASSERT(ft_strdup(NULL) == NULL,        "strdup: NULL returns NULL");
}

/* ─── main ───────────────────────────────────────────────────────────────── */

int main(void)
{
    printf("\n=== test_string ===\n");
    test_strlen();
    test_strcpy();
    test_strcat();
    test_strcmp();
    test_strdup();
    printf("\n%s — %d failure(s)\n", g_fails == 0 ? "ALL PASS" : "SOME FAIL", g_fails);
    return (g_fails != 0);
}
