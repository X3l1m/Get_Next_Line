#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDWR);
	//exit(0);
	char *domates = get_next_line(fd);
	printf("%s", domates);
	close(fd);
}
