/*
** ft_memset.c — fill n bytes of dst with the constant byte c.
**
** PRECONDITIONS (D-02 safe-first):
**   - dst may be NULL only if n == 0 (no-op). Passing NULL with n > 0
**     invokes undefined behaviour (mirrors libc — caller responsibility).
**
** EDUCATIONAL NOTE:
**   Cast to unsigned char* before filling to avoid signed-extension issues
**   on platforms where char is signed.
*/

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (dst == NULL || n == 0)
		return (dst);
	p = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
