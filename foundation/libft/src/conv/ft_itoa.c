/*
** ft_itoa.c — convert integer n to a heap-allocated decimal string.
**
** Handles INT_MIN correctly by working in negative space throughout.
**
** PRECONDITIONS (D-02 safe-first):
**   - Returns NULL on allocation failure.
**   - Caller must free the result.
*/

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/* count decimal digits needed (working in negative space to handle INT_MIN) */
static int	digit_count(int n)
{
	int	count;

	count = (n <= 0) ? 1 : 0;  /* sign or leading digit for 0 */
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;
	int		neg;
	long	num;

	neg = (n < 0);
	num = (long)n;
	len = digit_count(n) + neg;
	s = (char *)malloc(len + 1);
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (num == 0)
	{
		s[0] = '0';
		return (s);
	}
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		s[--len] = '0' + (char)(num % 10);
		num /= 10;
	}
	return (s);
}
