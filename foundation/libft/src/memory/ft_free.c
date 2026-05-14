/*
** ft_free.c — no-op for arena allocator v1.
**
** In arena v1, individual deallocation is not supported.
** This stub exists for API completeness and to allow callers
** to be written with ft_free calls that will work transparently
** when a real allocator is plugged in later.
**
** NOTE: Do not pass pointers obtained from stdlib malloc here —
**       that would be a memory leak. ft_malloc and ft_free are
**       a matched pair; stdlib malloc uses stdlib free.
*/

#include "libft.h"

void	ft_free(void *ptr)
{
	(void)ptr;  /* no-op: arena v1 does not support individual deallocation */
}
