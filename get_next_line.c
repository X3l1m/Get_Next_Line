#include "get_next_line.h"


int	check_line(char *buffer)
{
	static int x;

	if(!*buffer)
	{	
		write(1, "bos", 3);
		return(0);
	}

	x = 0;
	while (buffer[x])
	{
		if (buffer[x] == '\n')
			return(x);
		if (!buffer[x])
			return (-1);
		x++;
	}
	return(0);
}

char *get_next_line(int fd)
{
	static char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (0);

	int i = 0;
	while(i == 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		i = check_line(buffer);
		if (i == -1)
			return (buffer);
	}
	printf("%d", i);
	char *buff = malloc(i + 1);
	ft_strlcpy(buff, buffer, i+1);
	return (buff);
}