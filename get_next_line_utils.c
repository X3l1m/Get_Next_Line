#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (dstsize - 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (len);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	p;
	size_t	p1;

	p = ft_strlen(s1);
	p1 = ft_strlen(s2) + 1;
	join = malloc(p + p1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, p);
	ft_strlcpy(join + p, s2, p1);
	return (join);
}

char	*ft_strdup(char const *s1)
{
	char	*rtn;

	rtn = malloc(ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, ft_strlen(s1) + 1);
	return (rtn);
}

