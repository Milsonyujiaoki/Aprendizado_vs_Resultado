/*
** test_allocator.c — unit tests for ft_malloc / ft_free (arena v1).
**
** Edge cases covered (D-03 matrix):
**   - n == 0 → NULL
**   - small allocation returns non-NULL
**   - returned memory is zero-initialised
**   - successive allocations return different pointers
**   - ft_free is a no-op (no crash)
**   - 8-byte alignment
**
** NOTE: The arena is a static block — tests run in a single process and
**       share state. Tests are ordered to reflect realistic usage.
**       Arena exhaustion is not tested (would require a 1 MiB alloc loop).
*/

#include <stdio.h>
#include <stdint.h>
#include "../../include/libft.h"

static int g_fails = 0;

#define ASSERT(cond, label) \
    do { \
        if (cond) { printf("[PASS] %s\n", label); } \
        else       { printf("[FAIL] %s\n", label); g_fails++; } \
    } while (0)

static void test_malloc(void)
{
    /* n == 0 returns NULL */
    ASSERT(ft_malloc(0) == NULL,    "allocator: n==0 returns NULL");

    /* normal allocation */
    void *p1 = ft_malloc(16);
    ASSERT(p1 != NULL,              "allocator: 16-byte alloc returns non-NULL");

    /* zero-initialised */
    unsigned char *bytes = (unsigned char *)p1;
    int all_zero = 1;
    for (int i = 0; i < 16; i++)
        if (bytes[i] != 0) { all_zero = 0; break; }
    ASSERT(all_zero,                "allocator: returned memory is zero-initialised");

    /* alignment: address must be 8-byte aligned */
    ASSERT(((uintptr_t)p1 % 8) == 0, "allocator: 8-byte alignment");

    /* successive allocations are distinct */
    void *p2 = ft_malloc(16);
    ASSERT(p2 != NULL && p2 != p1,  "allocator: successive allocs return different pointers");

    /* ft_free is a no-op (no crash) */
    ft_free(p1);
    ft_free(NULL);
    ASSERT(1,                       "allocator: ft_free no-op (no crash)");
}

int main(void)
{
    printf("\n=== test_allocator ===\n");
    test_malloc();
    printf("\n%s — %d failure(s)\n", g_fails == 0 ? "ALL PASS" : "SOME FAIL", g_fails);
    return (g_fails != 0);
}
