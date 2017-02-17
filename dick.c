#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"


int main()
{
	int a;

	a = 10;
	ft_printf("[% 15.5p]\n", &a);
       printf("[% 15.5p]\n", &a);

	return (0);

}