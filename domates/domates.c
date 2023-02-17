#include <stdio.h>
#include <stdlib.h>

size_t domates(size_t x)
{
	x++;
	return(x);
}


int main()
{
	int x = -2;
	printf("%zu", domates((size_t)x));
}