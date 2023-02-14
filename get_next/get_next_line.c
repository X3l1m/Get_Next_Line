#include "get_next_line.h"

int	check_line(char* str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		if(!str[++i])
			return (-i);
	return (i);
}


int	read_line(char **line, char **mem, int fd)
{
	char*	buffer;
	int		readed;
	int		x;

	x = 0;
	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (free(buffer), 0);
		buffer[readed] = 0;
		x = check_line(buffer, '\n');
		if(x < 0)
			*line = ft_strjoin(*line, buffer, x);
		else if (x > 0)
		{
			*line = ft_strjoin(*line, buffer, x);
			*mem = ft_strdup(buffer + (x + 1));
			break;
		}
	}
	free(buffer);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;
	int			x;

	x = 0;
	line = malloc(1);
	line[0] = 0;
	if (!mem)
		x = read_line(&line, &mem, fd);
	else
	{
		x = check_line(mem, '\n');
		line = ft_strjoin(line, mem, x);
		mem = mem + (x + 1);
		if (x <= 0)
		{
			free(mem);
			x = read_line(&line, &mem, fd);
		}
	}
	if (!x)
		return (NULL);
	return(line);
}