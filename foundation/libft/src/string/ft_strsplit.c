/*
** ft_strsplit.c — split string s by delimiter c into NULL-terminated array.
**
** ALGORITHM (educational):
**   Pass 1: count tokens (consecutive delimiters produce no empty tokens).
**   Allocate array of (token_count + 1) pointers.
**   Pass 2: copy each token via ft_strdup.
**   On allocation failure: free previously allocated tokens and array.
**
** PRECONDITIONS (D-02 safe-first):
**   - If s is NULL, returns NULL.
**   - Returns NULL if any allocation fails (all prior work freed).
**   - Empty string ("") with any delimiter returns a valid array with 0 tokens
**     (array = { NULL }).
**   - Consecutive delimiters are collapsed (no empty-string tokens).
**
** CALLER RESPONSIBILITY:
**   Free each token, then free the array itself.
*/

#include "libft.h"
#include <stdlib.h>

/* count tokens in s split by c (consecutive delimiters collapse) */
static size_t	count_tokens(const char *s, char c)
{
	size_t	count;
	int		in_token;

	count = 0;
	in_token = 0;
	while (*s)
	{
		if (*s == c)
			in_token = 0;
		else if (!in_token)
		{
			in_token = 1;
			count++;
		}
		s++;
	}
	return (count);
}

/* return pointer to start of next token, advance *src past it */
static size_t	token_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/* free partially filled result array up to index n */
static void	free_partial(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_strsplit(const char *s, char c)
{
	size_t	total;
	char	**result;
	size_t	idx;
	size_t	tlen;

	if (s == NULL)
		return (NULL);
	total = count_tokens(s, c);
	result = (char **)malloc((total + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (*s && idx < total)
	{
		/* skip delimiters */
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		tlen = token_length(s, c);
		/* duplicate token */
		result[idx] = (char *)malloc(tlen + 1);
		if (result[idx] == NULL)
		{
			free_partial(result, idx);
			return (NULL);
		}
		ft_memcpy(result[idx], s, tlen);
		result[idx][tlen] = '\0';
		idx++;
		s += tlen;
	}
	result[idx] = NULL;
	return (result);
}
