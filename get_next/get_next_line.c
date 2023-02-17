#include "get_next_line.h"

int	check_line(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (i);
	return (-i);
}

int	read_line(char **line, char **mem, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		x;
	ssize_t	readed;

	x = 0;
	readed = read(fd, buffer, BUFFER_SIZE);
	if (readed <= 0)
		return (0);
	buffer[readed] = 0;
	x = check_line(buffer, '\n');
	if (x < 0)
	{
		*line = ft_strjoin(*line, buffer, (size_t)x);
		read_line(line, mem, fd);
	}
	else if (x > 0)
	{
		*line = ft_strjoin(*line, buffer, (size_t)x);
		if ((int)ft_strlen(buffer) > x)
			*mem = ft_strdup(buffer + x);
		return (1);
	}
	return (0);
}
char *freemem(char *mem, int x)
{
	char *newmem;
	int i;

	i = ft_strlen(mem);
	newmem = malloc(i - x + 1);
	i = 0;
	while (mem[x])
	{
		newmem[i++] = mem[x++];
	}
	newmem[i] = 0;
	free(mem);
	return(newmem);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;
	int			x;

	x = 0;
	line = ft_calloc(1, 1);
	if (!line)
		return (0);
	if (!mem)
		x = read_line(&line, &mem, fd);
	else
	{
		x = check_line(mem, '\n');
		line = ft_strjoin(line, mem, (size_t)x);
		if (x <= 0)
		{
			if (mem || x != 0)
				free(mem);
			x = read_line(&line, &mem, fd);
			if(*mem == 0)
			free(mem);
		}
		else
			mem = freemem(mem, x);
	}
	if (x <= 0 && !*line)
		return (free(line), NULL);
	return (line);
}
