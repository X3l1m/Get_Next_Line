#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	//get_next_line(fd);
	char *domates;
	domates = get_next_line(fd);//1
	//write(1, domates, 100);
	printf("%s", domates);
	domates = get_next_line(fd);//2
	// //write(1, domates, 10);
	printf("%s", domates);
	domates = get_next_line(fd);//3
	printf("%s", domates);
	domates = get_next_line(fd);//4
	printf("%s", domates);
	// domates = get_next_line(fd);//5
	// printf("%s", domates);
	close(fd);
}
