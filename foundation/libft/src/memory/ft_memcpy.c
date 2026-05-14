/*
** ft_memcpy.c — copy n bytes from src to dst (non-overlapping regions).
**
** PRECONDITIONS (D-02 safe-first):
**   - If dst or src is NULL and n > 0, returns NULL (safe-first deviation).
**   - Caller must guarantee non-overlapping regions; use ft_memmove otherwise.
**   - n == 0 returns dst immediately.
**
** EDUCATIONAL NOTE:
**   Iterates byte-by-byte to emphasise pointer arithmetic fundamentals.
**   A real compiler will vectorise this; the source stays readable intentionally.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (n == 0)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
