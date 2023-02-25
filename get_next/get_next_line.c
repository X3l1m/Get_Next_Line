#include "get_next_line.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
		{
			if (str[i])
				return (i);
			return (-i);
		}
	}
	return (0);
}

char	*read_line(char **line, int fd)
{
	ssize_t	readed;
	char	*buffer[BUFFER_SIZE + 1];
	int		lin;

	readed = dread(fd, buffer, BUFFER_SIZE);
	if (readed < 0)
	{
		line = NULL;
		return (NULL);
	}
	if (!readed)
		return (NULL);
	buffer[readed] = 0;
	lin = check_line(buffer);
	*line = ft_strjoin(*line, buffer, lin);
	if (lin > 0)
		return (ft_strdup(buffer + lin));
	else if (lin < 0)
		return (ft_strdup(buffer + (-lin)));
	return(read_line(*line, fd));
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	mem = read_line(&line, fd);
	if (!mem)
		return (line);
	
}