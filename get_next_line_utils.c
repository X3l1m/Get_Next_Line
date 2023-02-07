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
	if(!dstsize)
		return(len);
	while (dstsize - 1  && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (len);
}
