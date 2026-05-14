/*
** ft_memmove.c — copy n bytes from src to dst (overlap-safe).
**
** PRECONDITIONS (D-02 safe-first):
**   - If dst or src is NULL and n > 0, returns NULL (safe-first).
**   - n == 0 returns dst immediately.
**
** ALGORITHM (EDUCATIONAL NOTE):
**   If dst < src or regions do not overlap → forward copy (low→high).
**   If dst > src and they overlap              → backward copy (high→low).
**
**   The overlap condition is:
**     overlap = (src < dst) && (dst < src + n)
**   When overlap is true a forward pass would corrupt src before reading it.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s || d >= s + n)
	{
		/* forward copy: safe when dst is before src or no overlap */
		size_t i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		/* backward copy: safe when dst is inside src region */
		size_t i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dst);
}
