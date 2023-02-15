#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strjoin(char  *s1, char const *s2, size_t limit)
{
	char	*join;
	size_t	p;
	size_t	p1;

	if ((int)limit < 0)
		limit = -limit;
	p = ft_strlen(s1);
	p1 = limit;
	join = malloc(p + p1 + 1);
	if (!join)
		return (NULL);
	join[p + p1] = 0;
	ft_memcpy(join, s1, p);
	ft_memcpy(join + p, s2, p1);
	free(s1);
	return (join);
}

char	*ft_strdup(char const *s1)
{
	char	*rtn;
	int		len;

	len = ft_strlen(s1) + 1;
	rtn = malloc(len);
	if (!rtn)
		return (NULL);
	ft_memcpy(rtn, s1, len);
	return (rtn);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(char *)(s + n) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *) malloc (size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= (unsigned)ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] && i < len)
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		rtn[i] = s[i + start];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
