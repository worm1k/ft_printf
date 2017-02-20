#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"


int main()
{
	int i = 0, j = 0;

	i = ft_printf("[%0d]\t", 0);printf("[%d]\n", i);fflush(stdout);
	j =    printf("[%0d]\t", 0);printf("[%d]\n", j);fflush(stdout);
	i = ft_printf("[%.0d]\t", 0);printf("[%d]\n", i);fflush(stdout);
	j =    printf("[%.0d]\t", 0);printf("[%d]\n", j);fflush(stdout);
	i = ft_printf("[%2.0d]\t", 0);printf("[%d]\n", i);fflush(stdout);
	j =    printf("[%2.0d]\t", 0);printf("[%d]\n", j);fflush(stdout);
	/*
	printf("[");
	fflush(stdout);
	ft_printf("@moulitest: %.d %.0d", 42, 43);
	printf("]");
	fflush(stdout);
	printf("\n[");
	fflush(stdout);
	   printf("@moulitest: %.d %.0d", 42, 43);
	printf("]\n");
	fflush(stdout);
	*/
	return (0);

}