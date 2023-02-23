#include <stdio.h>
#include <stdlib.h>

int domates(void)
{
	char *mem;
	char *cop = "domates";
	int i = 0;
	mem =  malloc(8);
	while (i < 9)
	{
		mem[i] = cop[i];
		i++;
	}
	mem + 3;
	printf("%s", mem);
	//free(mem - 3);
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
	//printf("%d", i);
	system("leaks a.out");
}