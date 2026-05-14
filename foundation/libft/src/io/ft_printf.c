/*
** ft_printf.c — entry point for ft_printf.
**
** Scans fmt character by character:
**   - Non-'%' chars: written verbatim.
**   - '%' char: hand off to parser → emit pipeline.
**
** Returns total bytes written, or -1 on write error.
*/

#include "../../include/libft.h"
#include "../../include/internal/libft_internal.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			total;
	int			i;
	t_fmt_spec	spec;
	int			r;

	if (fmt == NULL)
		return (-1);
	va_start(args, fmt);
	total = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			r = (int)write(1, &fmt[i], 1);
			if (r < 0) { va_end(args); return (-1); }
			total += r;
			i++;
		}
		else
		{
			i++;  /* skip '%' */
			if (!ft_printf_parse(fmt, &i, &spec))
			{
				/* unknown specifier: emit '%' + the char verbatim */
				r = (int)write(1, "%", 1);
				if (r < 0) { va_end(args); return (-1); }
				total += r;
				continue ;
			}
			r = ft_printf_emit(spec, &args);
			if (r < 0) { va_end(args); return (-1); }
			total += r;
		}
	}
	va_end(args);
	return (total);
}
