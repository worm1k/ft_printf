#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

int main()
{
	int m = ft_printf("%#9.1X\n", 0);
    int n = printf("%#9.1X\n", 0);

	return (0);

}