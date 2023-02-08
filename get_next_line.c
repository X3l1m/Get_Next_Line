#include "get_next_line.h"


char *get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		readed = 1;

	line = malloc(sizeof(char));
	line[0] = 0;
	while(readed)
	{
		readed = read(fd, buffer, 7);
		buffer[4] = 0;
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break;
	}
	return (line);
}