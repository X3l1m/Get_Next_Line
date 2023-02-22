#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char const *s1)
{
	char	*rtn;

	rtn = malloc(ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, s1, ft_strlen(s1) + 1);
	return (rtn);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	p;
	size_t	p1;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	p = ft_strlen(s1);
	p1 = ft_strlen(s2) + 1;
	join = malloc(p + p1);
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, p);
	ft_memcpy(join + p, s2, p1);
	free(s1);
	return (join);
}