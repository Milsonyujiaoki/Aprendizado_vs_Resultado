/*
** test_smoke.c — smoke test for libft public API.
**
** Purpose: verify that every exported symbol can be called without crashing
** on a minimal valid input. Not a correctness test — that is each category
** suite's job. Smoke = "does it turn on without smoke?"
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/libft.h"

int main(void)
{
    printf("\n=== smoke test: libft ===\n");

    /* memory */
    char buf[32];
    ft_memset(buf, 0, 32);
    ft_bzero(buf, 32);
    ft_memcpy(buf, "smoke", 6);
    ft_memmove(buf + 8, buf, 6);
    printf("[smoke] memory functions: OK\n");

    /* string (stubs — implementations arrive in 02-02) */
    /* Uncomment as each symbol lands:
    ft_strlen("hello");
    ft_strcpy(buf, "hi");
    ft_strcat(buf, " there");
    ft_strcmp("a", "b");
    char *dup = ft_strdup("test"); ft_free(dup);
    char **parts = ft_strsplit("a,b", ',');
    (void)parts;
    */

    /* conv / io / allocator (stubs — arrive in 02-03) */
    /* Uncomment when 02-03 lands:
    ft_atoi("42");
    char *s = ft_itoa(42); ft_free(s);
    void *p = ft_malloc(16); ft_free(p);
    ft_printf("%s\n", "smoke");
    */

    printf("[smoke] all checks passed\n\n");
    return (0);
}
