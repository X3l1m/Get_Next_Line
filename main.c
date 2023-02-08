#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("text.txt", O_RDWR);
	char *domates = get_next_line(fd);
	write(1, domates, 17);
	//printf("%s", domates);
}
