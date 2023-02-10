#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int main()
{
<<<<<<< HEAD
	int fd = open("text.txt", O_RDWR);
	//exit(0);
	char *domates = get_next_line(fd);
	//char *domates2 = get_next_line(fd);
	//char buffer[5];
	//read(fd, buffer, 5);
=======
	int fd = open("text.txt", O_RDONLY);
	//get_next_line(fd);
	char *domates;
	domates = get_next_line(fd);
	//write(1, domates, 100);
>>>>>>> 8bfb2a9a506e9667436c343a5a39a9dca9d331e0
	printf("%s", domates);
	domates = get_next_line(fd);
	//write(1, domates, 10);
	printf("%s", domates);
	domates = get_next_line(fd);
	printf("%s", domates);
	domates = get_next_line(fd);
	printf("%s", domates);
	domates = get_next_line(fd);
	printf("%s", domates);
}
`