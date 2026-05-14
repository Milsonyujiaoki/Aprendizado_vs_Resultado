/*
** ft_printf_emit.c — render one argument to stdout according to spec.
**
** Supports: %c %s %d %i %u %x %% with width and precision (D-04).
**
** Width:     minimum field width (padded with spaces or '0' if zero_pad).
** Precision: for %s: max chars to print; for %d/%i/%u/%x: min digits.
**
** Returns number of bytes written, or -1 on write error.
*/

#include "../../include/internal/libft_internal.h"
#include "../../include/libft.h"
#include <unistd.h>
#include <stdlib.h>

/* ─── helpers ────────────────────────────────────────────────────────────── */

/* write a single char to fd 1 */
static int	emit_char(char c)
{
	return ((int)write(1, &c, 1));
}

/* write n pad chars (space or '0') to fd 1 */
static int	emit_pad(char pad, int n)
{
	int	written;

	written = 0;
	while (n-- > 0)
	{
		if (emit_char(pad) < 0)
			return (-1);
		written++;
	}
	return (written);
}

/* write a string of given len to fd 1 */
static int	emit_str(const char *s, int len)
{
	int	w;

	w = (int)write(1, s, (size_t)len);
	return (w < 0 ? -1 : w);
}

/* apply width padding: left/right-align a rendered value */
static int	pad_field(const char *val, int vlen, t_fmt_spec spec)
{
	int		written;
	int		pad_count;
	char	pad_char;

	written = 0;
	pad_count = spec.width - vlen;
	pad_char = (spec.zero_pad && !spec.left_align) ? '0' : ' ';
	if (!spec.left_align && pad_count > 0)
	{
		int r = emit_pad(pad_char, pad_count);
		if (r < 0) return (-1);
		written += r;
	}
	{
		int r = emit_str(val, vlen);
		if (r < 0) return (-1);
		written += r;
	}
	if (spec.left_align && pad_count > 0)
	{
		int r = emit_pad(' ', pad_count);
		if (r < 0) return (-1);
		written += r;
	}
	return (written);
}

/* ─── per-specifier render functions ────────────────────────────────────── */

static int	render_c(t_fmt_spec spec, va_list *args)
{
	char	c;
	int		written;

	c = (char)va_arg(*args, int);
	written = 0;
	if (!spec.left_align && spec.width > 1)
	{
		int r = emit_pad(' ', spec.width - 1);
		if (r < 0) return (-1);
		written += r;
	}
	{
		int r = emit_char(c);
		if (r < 0) return (-1);
		written += r;
	}
	if (spec.left_align && spec.width > 1)
	{
		int r = emit_pad(' ', spec.width - 1);
		if (r < 0) return (-1);
		written += r;
	}
	return (written);
}

static int	render_s(t_fmt_spec spec, va_list *args)
{
	const char	*s;
	int			slen;
	int			print_len;

	s = va_arg(*args, const char *);
	if (s == NULL)
		s = "(null)";
	slen = (int)ft_strlen(s);
	print_len = (spec.precision >= 0 && spec.precision < slen)
		? spec.precision : slen;
	return (pad_field(s, print_len, spec));
}

/* unsigned decimal or hex to string in buf (filled right→left) */
static int	uint_to_str(unsigned long n, int base, char *buf, int bufsz)
{
	const char	*hex = "0123456789abcdef";
	int			pos;

	pos = bufsz - 1;
	buf[pos] = '\0';
	if (n == 0)
	{
		buf[--pos] = '0';
		return (bufsz - 1 - pos);
	}
	while (n > 0)
	{
		buf[--pos] = hex[n % (unsigned long)base];
		n /= (unsigned long)base;
	}
	return (bufsz - 1 - pos);
}

static int	render_int(t_fmt_spec spec, va_list *args, int is_unsigned, int base)
{
	char			buf[32];
	char			num_buf[30];
	int				num_len;
	int				neg;
	unsigned long	uval;
	long			sval;
	int				min_digits;
	int				total_len;

	neg = 0;
	if (is_unsigned)
		uval = (unsigned long)va_arg(*args, unsigned int);
	else
	{
		sval = (long)va_arg(*args, int);
		neg  = (sval < 0);
		uval = neg ? (unsigned long)(-sval) : (unsigned long)sval;
	}
	num_len = uint_to_str(uval, base, num_buf, (int)sizeof(num_buf));
	min_digits = (spec.precision > num_len) ? spec.precision : num_len;
	total_len = min_digits + (neg ? 1 : 0);
	/* build final string in buf */
	{
		int i = 0;
		if (neg)
			buf[i++] = '-';
		/* zero-pad to min_digits */
		int zero_prefix = min_digits - num_len;
		while (zero_prefix-- > 0)
			buf[i++] = '0';
		/* copy digits */
		const char *digits = num_buf + (sizeof(num_buf) - 1 - num_len);
		for (int j = 0; j < num_len; j++)
			buf[i++] = digits[j];
		buf[i] = '\0';
		total_len = i;
	}
	return (pad_field(buf, total_len, spec));
}

/* ─── dispatch ───────────────────────────────────────────────────────────── */

int	ft_printf_emit(t_fmt_spec spec, va_list *args)
{
	if (spec.specifier == '%')
		return (emit_char('%'));
	if (spec.specifier == 'c')
		return (render_c(spec, args));
	if (spec.specifier == 's')
		return (render_s(spec, args));
	if (spec.specifier == 'd' || spec.specifier == 'i')
		return (render_int(spec, args, 0, 10));
	if (spec.specifier == 'u')
		return (render_int(spec, args, 1, 10));
	if (spec.specifier == 'x')
		return (render_int(spec, args, 1, 16));
	return (0);  /* unknown — treat as 0 chars */
}
