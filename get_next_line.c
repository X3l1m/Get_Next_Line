#include "get_next_line.h"

int	check_line(char *buffer)
{
	static int x;
	write(1, &buffer, 7);
	if(!buffer)
		return(0);
	x = 0;
	while (buffer[x])
	{
		if (buffer[x] == '\n')
			return(1);
		x++;
	}
	
	return(0);
}


char *get_next_line(int fd)
{
	char *buffer;

	//check_line(buffer);
	read(fd, &buffer, BUFFER_SIZE);
	return (&buffer);
}