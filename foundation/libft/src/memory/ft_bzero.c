/*
** ft_bzero.c — zero n bytes of memory starting at s.
**
** PRECONDITIONS (D-02 safe-first):
**   - If s is NULL, n must be 0. n == 0 is always a no-op.
**
** EDUCATIONAL NOTE:
**   Implemented as a thin wrapper over ft_memset to demonstrate
**   the relationship between the two stdlib functions.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (s == NULL || n == 0)
		return ;
	ft_memset(s, 0, n);
}
