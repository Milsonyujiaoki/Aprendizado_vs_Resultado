/*
** libft_internal.h — Internal helpers shared across libft categories.
** NOT part of the public API. Do not include from outside foundation/libft/src/.
*/

#ifndef LIBFT_INTERNAL_H
# define LIBFT_INTERNAL_H

# include <stddef.h>
# include <stdarg.h>

/* ─── printf internal types ─────────────────────────────────────────────── */

/*
** t_fmt_spec — parsed format specifier produced by the printf parser.
** Carries all fields needed by the emit stage.
*/
typedef struct s_fmt_spec
{
	int		width;        /* minimum field width (0 = none) */
	int		precision;    /* precision (-1 = none) */
	int		left_align;   /* 1 if '-' flag present */
	int		zero_pad;     /* 1 if '0' flag present */
	char	specifier;    /* one of: c s d i u x % */
}	t_fmt_spec;

/* ─── printf pipeline ────────────────────────────────────────────────────── */

/*
** ft_printf_parse — scan fmt starting at *pos (must point at char after '%').
** Fills spec, advances *pos past the specifier character.
** Returns 1 on valid specifier, 0 on unknown/end-of-string.
*/
int		ft_printf_parse(const char *fmt, int *pos, t_fmt_spec *spec);

/*
** ft_printf_emit — render one argument according to spec into fd 1.
** Returns number of bytes written, or -1 on error.
*/
int		ft_printf_emit(t_fmt_spec spec, va_list *args);

/* ─── Arena allocator internals ─────────────────────────────────────────── */

# define FT_ARENA_SIZE  (1024 * 1024)  /* 1 MiB static arena */

typedef struct s_arena
{
	char	buf[FT_ARENA_SIZE];
	size_t	used;
}	t_arena;

/* Access the process-global arena. */
t_arena	*ft_arena_get(void);

#endif
