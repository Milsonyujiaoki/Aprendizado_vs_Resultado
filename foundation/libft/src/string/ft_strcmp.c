/*
** ft_strcmp.c — compare s1 and s2 lexicographically.
**
** Returns negative if s1 < s2, 0 if equal, positive if s1 > s2.
**
** PRECONDITIONS (D-02 safe-first):
**   - If either pointer is NULL, returns 0 (safe-first: documented undefined
**     behaviour; caller should not rely on meaningful ordering from NULL).
*/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
