#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("text.txt", O_RDWR);
	char *domates = get_next_line(fd);
	printf("%s", domates);
}
