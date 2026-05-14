/*
** ft_strcpy.c — copy src into dst (including NUL terminator).
**
** PRECONDITIONS (D-02 safe-first):
**   - If dst or src is NULL, returns NULL.
**   - dst must have enough space for strlen(src)+1 bytes (caller responsibility).
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
