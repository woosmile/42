#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	c = '@';
	char *s = "abcdefgh";
	int	result_o;
	int	result_ft;
	result_o = printf("test test %c %s %p\n", c, s, &c);
	result_ft = ft_printf("test test %c %s %p\n", c, s, &c);

	printf("%d, %d\n", result_o, result_ft);
	return (0);
}