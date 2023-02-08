#include <stdio.h>
#include <unistd.h>
int main()
{
	int i = -5;
	while (i)
	{
		i++;
		if (i == 5)
			i = 15;
		if (i == 10)
			break;
		if (i == 15)
		{
			write(1, "domateslendin", 13);
			break;
		}
	}
	printf("%d", i);
}