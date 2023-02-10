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

char *get_next_line(int fd)
{
<<<<<<< HEAD
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (0);
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (NULL);
	int i = 0;
	while(i == 0)
=======
	char		*buffer;
	char		*line;
	static char	*mem;
	int			readed;

	readed = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
	return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if	(!buffer)
		return (0);
 	if (!mem)
		mem = malloc(0);
	if (!mem)
		return (0);
	line = ft_strdup(mem);
	ft_bzero(mem);
	readed = find_line(line, mem);
	while(readed)
>>>>>>> 8bfb2a9a506e9667436c343a5a39a9dca9d331e0
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			return (free(buffer), free(line), NULL);
		buffer[readed] = 0;
		line = ft_strjoin(line, buffer);
		readed = find_line(line, mem);
	}
<<<<<<< HEAD
	//printf("%d", i);
	char *buff = malloc(i + 1);
	ft_strlcpy(buff, buffer, i+1);
	return (buff);
}
=======
	free(buffer);
	return (line);
}


>>>>>>> 8bfb2a9a506e9667436c343a5a39a9dca9d331e0
