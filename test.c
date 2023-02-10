#include <stdio.h>
#include <unistd.h>
int find_next(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != '\n')
		if (!str[i])
			return (-i);
	return (i);
}
int main()
{
	char ana[] = "domates";
	printf("%d", find_next(ana));
}