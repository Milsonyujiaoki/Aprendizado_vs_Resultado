/*
** ft_strcat.c — append src to the end of dst.
**
** PRECONDITIONS (D-02 safe-first):
**   - If dst or src is NULL, returns NULL.
**   - dst must be NUL-terminated and have enough space (caller responsibility).
*/

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	dlen;
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	dlen = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dst);
}
