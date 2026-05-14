/*
** ft_atoi.c — convert initial decimal integer string to int.
**
** Algorithm:
**   1. Skip leading whitespace (space, \t, \n, \v, \f, \r).
**   2. Consume optional '+' or '-'.
**   3. Consume digits until non-digit.
**
** PRECONDITIONS (D-02 safe-first):
**   - If s is NULL, returns 0.
**
** LIMITATIONS (documented):
**   - Overflow behaviour is undefined (educational scope).
**   - Does not handle hexadecimal or octal prefixes.
*/

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	result;
	int		sign;

	if (s == NULL)
		return (0);
	result = 0;
	sign = 1;
	/* skip whitespace */
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	/* optional sign */
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	/* digits */
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return ((int)(result * sign));
}
