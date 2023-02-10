#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDWR);
	//exit(0);
	char *domates = get_next_line(fd);
	//char *domates2 = get_next_line(fd);
	//char buffer[5];
	//read(fd, buffer, 5);
	printf("%s", domates);
	//printf("%s", domates2);
	//write(1, domates, 10);
	close(fd);
}
