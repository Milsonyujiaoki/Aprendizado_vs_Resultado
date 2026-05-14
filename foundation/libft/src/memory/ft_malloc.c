/*
** ft_malloc.c — educational arena allocator (v1).
**
** DESIGN (arena model):
**   One static 1 MiB buffer (FT_ARENA_SIZE) per process.
**   Allocations advance a cursor; memory is never individually freed.
**   All bytes are zero-initialised on first use (static storage).
**
** INVARIANTS:
**   - Allocations are 8-byte aligned.
**   - Requesting 0 bytes returns NULL (documented).
**   - Exhausted arena returns NULL.
**
** LIMITATIONS (educational scope — documented in INTERNALS.md):
**   - Not thread-safe.
**   - ft_free is a no-op (arena v1).
**   - Arena is never reset during process lifetime.
*/

#include "../../include/libft.h"
#include "../../include/internal/libft_internal.h"

/* alignment helper: round up to next multiple of 8 */
static size_t	align8(size_t n)
{
	return ((n + 7) & ~(size_t)7);
}

t_arena	*ft_arena_get(void)
{
	static t_arena arena;  /* zero-initialised by C static storage rules */
	return (&arena);
}

void	*ft_malloc(size_t n)
{
	t_arena	*a;
	size_t	aligned;
	void	*ptr;

	if (n == 0)
		return (NULL);
	aligned = align8(n);
	a = ft_arena_get();
	if (a->used + aligned > FT_ARENA_SIZE)
		return (NULL);
	ptr = (void *)(a->buf + a->used);
	a->used += aligned;
	return (ptr);
}
