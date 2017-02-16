#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print2(char n)
{
	for (int i = 128; i >= 1; i >>= 1)
	{
		if (i & n)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}
void ft_free(char **str)
{
	free(*str);
	*str = 0;
}

int main()
{
	/*
	char n = 167;
	char res = 0;
	print2(n);
	res = (n & 128) >> 7 | res;
	res = (n & 64) >> 5 | res;
	res = (n & 32) >> 3 | res;
	res = (n & 16) >> 1 | res;

	res = (n & 8) << 1 | res;
	res = (n & 4) << 3 | res;
	res = (n & 2) << 5 | res;
	res = (n & 1) << 7 | res;
	print2(res);
	*/
	char *hui;

	hui = (char *)malloc(32);
	strcpy(hui, "hui");
	printf("%s\n", hui);
	ft_free(&hui);
	printf("%s\n", hui);

	return (0);

}