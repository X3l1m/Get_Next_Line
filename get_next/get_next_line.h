#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2, size_t limit);
char	*ft_strdup(char *s1);

#endif
