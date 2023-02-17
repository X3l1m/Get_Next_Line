#include "get_next_line.h"

void	ft_bzero(char *s)
{
	while (*s)
		*s++ = 0;
}

int	find_line(char *line, char *mem)
{
	while (*line != '\n')
		if (!*line++)
			return (1);
	while (*++line)
	{
		*mem++ = *line;
		*line = 0;
	}
	return (0);
}

int	read_line(char **line, char **mem, int fd)
{
	char	*buffer;
	int		readed;

	buffer = malloc(BUFFER_SIZE + 1);
	if	(!buffer)
		return (0);
	while(readed)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			{
				if (**line && readed == 0)
					break;
				return (0);
			}
		buffer[readed] = 0;
		*line = ft_strjoin(*line, buffer);
		readed = find_line(*line, *mem);
	}
	free(buffer);
	return (1);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*mem;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (NULL);
 	if (!mem)
	{
		mem = malloc(0);
		ft_bzero(mem);
	}
	if (!mem)
		return (0);
	line = ft_strdup(mem);
	ft_bzero(mem);
	if(find_line(line, mem))
		if(!read_line(&line, &mem, fd))
			return (NULL);
	return (line);
}
