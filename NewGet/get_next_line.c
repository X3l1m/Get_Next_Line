#include "get_next_line.h"

int check_line(char *str)
{
	int i;

	i = 0;
	while(str[i])
		if(str[i++] == '\n')
		{
			if(str[i])
				return (i);
			return (-i);
		}
	return (0);
}

char	*read_line(int fd, char *mem)
{
	ssize_t readed;

	char buffer[BUFFER_SIZE + 1];
	readed = read(fd, buffer, BUFFER_SIZE);
	buffer[readed] = 0;
	if (!readed)
		return(mem);
	if (readed < 0)
		return (NULL);
	mem = ft_strjoin(mem, buffer);
	if	(check_line(mem))
		return (mem);
	return(read_line(fd, mem));
}

char	*trim_mem(char ***mem, int point)
{
	char *line;
	line = malloc(point);
	line[point] = 0;
	ft_memcpy(line, **mem, point);
	**mem = **mem + point;
	return (line);
}

char	*find_next(char **mem)
{
	char	*line;
	int		i;
	
	i = check_line(*mem);
	if (i <= 0)
	{
		line = ft_strdup(*mem);
		*mem = NULL;
		free(*mem);
		return(line);
	}
	line = trim_mem(&mem, i);
	return(line);
}

char *get_next_line(int fd)
{
	static char	*mem;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (NULL);
	if (!mem || !check_line(mem))
		mem = read_line(fd, mem);
	if(!mem)
		return (NULL);
	line = find_next(&mem);
	return (line);
}
