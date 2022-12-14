#include "ft_printf_bonus.h"
#include <stdio.h>

void	bonus_test()
{
	int		result_o = 0;
	int		result_ft = 0;

	char	c = '@';
	char 	*s = "TEST ABCDEFG 12345789 !@#$%%^&*()_+=\\";
	int		num = 123456789;
	
	printf("\n----------ft_printf BONUS test start----------\n\n");

	//printf("original printf\n");
	//result_o = printf("TEST : %c", c);

	ft_printf("\nft_printf\n\n");
	result_ft = ft_printf("TEST : %c", c);

	printf("\n");
	printf("original printf return : %d\n", result_o);
	printf("ft_printf return       : %d\n", result_ft);

	printf("\n----------ft_printf BONUS test end----------\n\n");
}

void	mandatory_test()
{
	int		result_o;
	int		result_ft;

	char	c = '@';
	char 	*s = "TEST ABCDEFG 12345789 !@#$%%^&*()_+=\\";
	int		num = 123456789;
	
	printf("\n----------ft_printf MANDATORY test start----------\n\n");

	printf("original printf\n");
	result_o = printf("char : %c, string : %s, addr : %p, nbr_d : %d, nbr_i : %i, nbr_u : %u, nbr_x : %x, nbr_X : %X\n", c, s, &c, num, num, num, num, num);
	//ft_printf("\nft_printf\n");
	//result_ft = ft_printf("char : %c, string : %s, addr : %p, nbr_d : %d, nbr_i : %i, nbr_u : %u, nbr_x : %x, nbr_X : %X\n", c, s, &c, num, num, num, num, num);
	/*
	printf("original printf : NULL TEST\n");
	result_o = printf("NULL STRING : %s, NULL ADDR : %p\n", NULL, NULL);
	ft_printf("\nft_printf : NULL TEST\n");
	result_ft = ft_printf("NULL STRING : %s, NULL ADDR : %p\n", NULL, NULL);
	*/
	printf("\n");
	printf("original printf return : %d\n", result_o);
	printf("ft_printf return       : %d\n", result_ft);

	printf("\n----------ft_printf MANDATORY test end----------\n\n");
}

int	main(void)
{
	//mandatory_test();
	bonus_test();

	return (0);
}
