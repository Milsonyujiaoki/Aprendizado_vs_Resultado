/*
** ft_strlen.c — return the length of string s (excludes '\0').
**
** PRECONDITIONS (D-02 safe-first):
**   - If s is NULL, returns 0 (safe-first divergence: libc is undefined).
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	if (s == NULL)
		return (0);
	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}
