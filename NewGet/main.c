#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd = open("read_error.txt", O_RDONLY);
	//get_next_line(fd);
	char *domates = "";
	while (domates)
	{
		domates = get_next_line(fd);
		printf("%s", domates);
		free(domates);
	}
	
	// domates = get_next_line(fd);//1
	// printf("%s", domates);
	// free(domates);

	// domates = get_next_line(fd);//2
	// printf("%s", domates);
	// free(domates);

	// domates = get_next_line(fd);//3
	// printf("%s", domates);
	// free(domates);

	// domates = get_next_line(fd);//4
	// printf("%s", domates);
	// free(domates);

	// domates = get_next_line(fd);//5
	// printf("%s", domates);
	// free(domates);

	// domates = get_next_line(fd);//6
	// printf("%s", domates);
	// free(domates);

	close(fd);
	system("leaks main");
}
