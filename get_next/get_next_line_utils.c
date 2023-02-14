#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (n > i)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t limit)
{
	char	*join;
	size_t	p;
	size_t	p1;

	if ((int)limit < 0)
		limit = -limit;
	p = ft_strlen(s1);
	p1 = limit + 1;
	join = malloc(p + p1);
	if (!join)
		return (NULL);
	join[p + p1] = 0;
	ft_memcpy(join, s1, p);
	ft_memcpy(join + p, s2, p1);
	free((char *)s1);
	return (join);
}

char	*ft_strdup(char *s1)
{
	char	*rtn;

	rtn = malloc(ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	ft_memcpy(rtn, s1, ft_strlen(s1) + 1);
	return (rtn);
}
