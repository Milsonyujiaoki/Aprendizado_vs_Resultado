/*
** ft_printf_parser.c — parse one format specifier after the '%' character.
**
** GRAMMAR handled:
**   %[-][0][width][.precision]specifier
**
** Where specifier ∈ { c, s, d, i, u, x, % }
** width and precision are unsigned decimal integers.
**
** Returns 1 on valid specifier, 0 on unknown specifier or end-of-string.
** On return, *pos points to the character AFTER the specifier.
*/

#include "../../include/internal/libft_internal.h"

/* read an unsigned decimal integer from fmt at *pos, advance *pos */
static int	parse_number(const char *fmt, int *pos)
{
	int	n;

	n = 0;
	while (fmt[*pos] >= '0' && fmt[*pos] <= '9')
	{
		n = n * 10 + (fmt[*pos] - '0');
		(*pos)++;
	}
	return (n);
}

int	ft_printf_parse(const char *fmt, int *pos, t_fmt_spec *spec)
{
	/* zero-initialise */
	spec->width      = 0;
	spec->precision  = -1;
	spec->left_align = 0;
	spec->zero_pad   = 0;
	spec->specifier  = '\0';

	/* flags: '-' and '0' */
	while (fmt[*pos] == '-' || fmt[*pos] == '0')
	{
		if (fmt[*pos] == '-')
			spec->left_align = 1;
		else if (!spec->left_align)          /* '0' flag ignored when '-' is set */
			spec->zero_pad = 1;
		(*pos)++;
	}

	/* width */
	if (fmt[*pos] >= '1' && fmt[*pos] <= '9')
		spec->width = parse_number(fmt, pos);

	/* precision */
	if (fmt[*pos] == '.')
	{
		(*pos)++;
		spec->precision = parse_number(fmt, pos);
	}

	/* specifier */
	if (fmt[*pos] == '\0')
		return (0);
	spec->specifier = fmt[*pos];
	(*pos)++;
	/* validate */
	{
		const char	valid[] = "csdixu%";
		int			j = 0;
		int			found = 0;
		while (valid[j])
		{
			if (valid[j] == spec->specifier) { found = 1; break ; }
			j++;
		}
		if (!found)
			return (0);
	}
	return (1);
}
