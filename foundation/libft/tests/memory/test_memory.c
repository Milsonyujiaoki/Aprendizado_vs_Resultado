/*
** test_memory.c — unit tests for libft memory category.
**
** Pattern: each section is labelled TEST_<func>_<scenario>.
** Print PASS/FAIL per case and return non-zero on any failure.
**
** Edge cases covered (D-03 matrix):
**   - NULL pointer inputs
**   - n == 0 (no-op)
**   - overlap detection (ft_memmove)
**   - single-byte fill
**   - fill value 0 vs non-zero
*/

#include <stdio.h>
#include <string.h>
#include "../../include/libft.h"

static int g_fails = 0;

#define ASSERT(cond, label) \
    do { \
        if (cond) { printf("[PASS] %s\n", label); } \
        else       { printf("[FAIL] %s\n", label); g_fails++; } \
    } while (0)

/* ─── ft_memset ──────────────────────────────────────────────────────────── */

static void test_memset(void)
{
    char buf[8];

    /* basic fill */
    ft_memset(buf, 'A', 5);
    ASSERT(buf[0] == 'A' && buf[4] == 'A', "memset: fills 5 bytes with A");

    /* n == 0 — no change */
    buf[0] = 'X';
    ft_memset(buf, 'Z', 0);
    ASSERT(buf[0] == 'X', "memset: n==0 is a no-op");

    /* fill with 0 */
    ft_memset(buf, 0, 8);
    ASSERT(buf[3] == 0 && buf[7] == 0, "memset: fill zero");

    /* NULL + n==0 → no crash, returns NULL */
    void *r = ft_memset(NULL, 0, 0);
    ASSERT(r == NULL, "memset: NULL+n==0 returns NULL");
}

/* ─── ft_bzero ───────────────────────────────────────────────────────────── */

static void test_bzero(void)
{
    char buf[8];

    ft_memset(buf, 0xFF, 8);
    ft_bzero(buf, 8);
    int all_zero = 1;
    for (int i = 0; i < 8; i++)
        if (buf[i] != 0) { all_zero = 0; break; }
    ASSERT(all_zero, "bzero: zeros exactly n bytes");

    /* n == 0 — no change */
    buf[0] = 'Q';
    ft_bzero(buf, 0);
    ASSERT(buf[0] == 'Q', "bzero: n==0 is a no-op");

    /* NULL + n==0 → no crash */
    ft_bzero(NULL, 0);
    ASSERT(1, "bzero: NULL+n==0 no crash");
}

/* ─── ft_memcpy ──────────────────────────────────────────────────────────── */

static void test_memcpy(void)
{
    const char src[] = "hello";
    char dst[8];

    ft_memcpy(dst, src, 6);
    ASSERT(memcmp(dst, src, 6) == 0, "memcpy: copies 6 bytes correctly");

    /* n == 0 */
    dst[0] = 'Z';
    ft_memcpy(dst, src, 0);
    ASSERT(dst[0] == 'Z', "memcpy: n==0 is a no-op");

    /* NULL src → NULL returned */
    void *r = ft_memcpy(dst, NULL, 3);
    ASSERT(r == NULL, "memcpy: NULL src returns NULL");

    /* NULL dst → NULL returned */
    r = ft_memcpy(NULL, src, 3);
    ASSERT(r == NULL, "memcpy: NULL dst returns NULL");
}

/* ─── ft_memmove — overlap ───────────────────────────────────────────────── */

static void test_memmove(void)
{
    char buf[16];

    /* non-overlapping forward */
    memcpy(buf, "abcdef\0\0\0\0\0\0\0\0\0", 15);
    ft_memmove(buf + 5, buf, 5);
    ASSERT(buf[5] == 'a' && buf[9] == 'e', "memmove: non-overlap forward");

    /* dst inside src (overlap, forward naive would corrupt) */
    memcpy(buf, "abcdefghij\0\0\0\0\0", 15);
    ft_memmove(buf + 2, buf, 8);
    ASSERT(buf[2] == 'a' && buf[9] == 'g', "memmove: overlap dst>src backward copy");

    /* src inside dst (the other direction) */
    memcpy(buf, "\0\0abcdefghij\0\0", 15);
    ft_memmove(buf, buf + 2, 8);
    ASSERT(buf[0] == 'a' && buf[7] == 'h', "memmove: overlap src>dst forward copy");

    /* n == 0 */
    buf[0] = 'X';
    ft_memmove(buf, buf + 1, 0);
    ASSERT(buf[0] == 'X', "memmove: n==0 is a no-op");

    /* NULL → NULL */
    void *r = ft_memmove(NULL, buf, 3);
    ASSERT(r == NULL, "memmove: NULL dst returns NULL");
}

/* ─── main ───────────────────────────────────────────────────────────────── */

int main(void)
{
    printf("\n=== test_memory ===\n");
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    printf("\n%s — %d failure(s)\n", g_fails == 0 ? "ALL PASS" : "SOME FAIL", g_fails);
    return (g_fails != 0);
}
