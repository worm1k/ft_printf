#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"


int main()
{
	int len;
	int n , m;

	printf("FT:[");fflush(stdout);
	n = ft_printf("12345%20n67890", &len);
	printf("]:[%d]\n", len);
	fflush(stdout);


	printf("   [");fflush(stdout);   
	m = printf("12345%20n67890", &len);
	fflush(stdout);
	printf("]:[%d]\n", len);
	fflush(stdout);

	printf("L:[%d]\n", len);
	return (0);
}