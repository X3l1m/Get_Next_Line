#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

char	*get_next_line(int fd);
int	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void * src, size_t n);
char	*ft_strjoin(char  *s1, char const *s2, size_t limit);
char	*ft_strdup(char const *s1);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
