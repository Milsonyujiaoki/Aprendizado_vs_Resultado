/*
** libft.h — Public API for libft (educational libc reimplementation).
**
** CONTRACT (D-02: safe-first)
** - NULL pointer inputs return NULL / 0 / undefined behavior as documented per function.
** - Every function documents its preconditions in the comment above its prototype.
** - Behaviors that diverge from libc are explicitly noted.
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/* ─── Memory ──────────────────────────────────────────────────────────────── */

/*
** ft_memset — fill memory with a constant byte.
** dst must not be NULL. n == 0 is a no-op.
** Returns dst.
*/
void	*ft_memset(void *dst, int c, size_t n);

/*
** ft_bzero — zero out n bytes starting at s.
** s must not be NULL. n == 0 is a no-op.
*/
void	ft_bzero(void *s, size_t n);

/*
** ft_memcpy — copy n bytes from src to dst (no-overlap assumed).
** If dst or src is NULL and n > 0, returns NULL (safe-first, diverges from libc).
** n == 0 returns dst immediately.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
** ft_memmove — copy n bytes from src to dst (overlap-safe).
** If dst or src is NULL and n > 0, returns NULL (safe-first).
** n == 0 returns dst immediately.
*/
void	*ft_memmove(void *dst, const void *src, size_t n);

/* ─── String ─────────────────────────────────────────────────────────────── */

/*
** ft_strlen — return the number of bytes in s before '\0'.
** If s is NULL returns 0 (safe-first, diverges from libc).
*/
size_t	ft_strlen(const char *s);

/*
** ft_strcpy — copy src into dst including '\0'. dst must have room.
** If dst or src is NULL returns NULL (safe-first).
*/
char	*ft_strcpy(char *dst, const char *src);

/*
** ft_strcat — append src to dst. dst must be NUL-terminated and have room.
** If dst or src is NULL returns NULL (safe-first).
*/
char	*ft_strcat(char *dst, const char *src);

/*
** ft_strcmp — compare s1 and s2 lexicographically.
** If either is NULL returns 0 (safe-first: treat as equal/undefined, documented).
*/
int		ft_strcmp(const char *s1, const char *s2);

/*
** ft_strdup — allocate and return a copy of s.
** If s is NULL returns NULL.
** Caller must free the result.
*/
char	*ft_strdup(const char *s);

/*
** ft_strsplit — split s by delimiter c, return NULL-terminated array of tokens.
** Consecutive delimiters produce no empty tokens.
** If s is NULL returns NULL. Caller must free each token and the array.
*/
char	**ft_strsplit(const char *s, char c);

/* ─── Conversion ─────────────────────────────────────────────────────────── */

/*
** ft_atoi — convert initial portion of s to int.
** Handles optional leading whitespace and sign. Overflow behaviour is undefined
** (educational scope — document in INTERNALS.md).
** If s is NULL returns 0 (safe-first).
*/
int		ft_atoi(const char *s);

/*
** ft_itoa — convert n to a heap-allocated decimal string.
** Handles INT_MIN. Returns NULL on allocation failure.
** Caller must free the result.
*/
char	*ft_itoa(int n);

/* ─── Memory allocator ───────────────────────────────────────────────────── */

/*
** ft_malloc — educational arena allocator.
** Returns pointer to n bytes of zeroed memory from internal arena.
** Returns NULL if n == 0 or arena is exhausted.
** LIMIT: not thread-safe; arena is a single static block.
*/
void	*ft_malloc(size_t n);

/*
** ft_free — no-op in arena allocator v1 (documented limitation).
** Included for API completeness; individual deallocation not supported.
*/
void	ft_free(void *ptr);

/* ─── I/O ────────────────────────────────────────────────────────────────── */

/*
** ft_printf — educational printf implementation.
** Supports: %c %s %d %i %u %x %% with width and precision.
** Returns number of characters written, or -1 on error.
*/
int		ft_printf(const char *fmt, ...);

#endif
