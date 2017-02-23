#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"
#include <locale.h>

#define CASE "%010.5S" 
#define VARG str

int main()
{
	int len;
	int n, m;
	//wchar_t *str = L"ணஒஐ";
	wchar_t *str = L"😀ண";

	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("FT_:[");fflush(stdout);
	n = ft_printf(CASE, str);
//	n = ft_printf("%.p", 0);
	printf("]:[%d]\n", n);
	fflush(stdout);

	//wchar_t *str;
	//scanf("%S", str);
	printf("STD:[");fflush(stdout);   
	m = printf(CASE, str);
//	m = printf("%.p", 0);
	fflush(stdout);
	printf("]:[%d]\n", m);
	fflush(stdout);

	return (0);
}