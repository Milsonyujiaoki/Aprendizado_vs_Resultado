/*
** ft_strdup.c — allocate and return a copy of s on the heap.
**
** PRECONDITIONS (D-02 safe-first):
**   - If s is NULL, returns NULL.
**   - Returns NULL if allocation fails.
**   - Caller must free the returned pointer.
**
** EDUCATIONAL NOTE:
**   Uses stdlib malloc directly (not ft_malloc) because strdup
**   must return individually free-able pointers, which the arena
**   allocator cannot guarantee in v1.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
