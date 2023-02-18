#include <stdio.h>
#include <stdlib.h>

int domates(void)
{
	char *mem;
	mem =  calloc(10, 1);
	free(mem);
	if (!mem)
		return(0);
	if  (mem)
		return (1);
	return(2);
}


int main()
{
	int i;
	i = domates();
	printf("%d", i);
}