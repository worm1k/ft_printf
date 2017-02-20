#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"


int main()
{
	int n , m;

	printf("FT:[");fflush(stdout);
	n = ft_printf("%S", L"Á±≥");
	printf("]:[%d]\n", n);
	fflush(stdout);


	printf("   [");fflush(stdout);   
	m = printf("%S", L"Á±≥");
	fflush(stdout);
	printf("]:[%d]\n", m);
	fflush(stdout);
	return (0);
}