#include "ft_printf_bonus.h"
#include <stdio.h>

void	bonus_test()
{
	int	result_o = 0;
	int	result_ft = 0;

	char	c = '@';
	char	*s = "TEST STRING";
	int		num = -123123;

	printf("\n----------ft_printf BONUS test start----------\n\n");

	result_o = printf("%#70.10x", num);
	printf("\n");
	result_ft = ft_printf("%#70.10x", num);
	//result_o = printf("TEST : %5.6d, %-20p, %-105.100s, %%%%%c, %4c, %.1s %d %% \n", num, s, s, c, c, s, num);
	//result_ft = ft_printf("TEST : %5.6d, %-20p, %-105.100s, %%%%%c, %4c, %.1s %d %% \n", num, s, s, c, c, s, num);
	/*
	result_o = printf("1. %d, %0d, %1d, %2d, %3d, %4d, %5d, %10d, %20d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("1. %d, %0d, %1d, %2d, %3d, %4d, %5d, %10d, %20d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");
	
	result_o = printf("2. %.d, %0.d, %1.d, %2.d, %3.d, %4.d, %5.d, %10.d, %20.d.", num, num, num, num, num, num, num, num, num);
	printf("\n");

	result_ft = ft_printf("2. %.d, %0.d, %1.d, %2.d, %3.d, %4.d, %5.d, %10.d, %20.d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");
	
	result_o = printf("3. %.d, %0.0d, %0.1d, %0.2d, %0.3d, %0.4d, %0.5d, %0.10d, %0.20d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("3. %.d, %0.0d, %0.1d, %0.2d, %0.3d, %0.4d, %0.5d, %0.10d, %0.20d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");
	
	result_o = printf("4. %20.d, %20.1d, %20.2d, %20.3d, %20.4d, %20.5d, %20.10d, %20.20d, %20.50d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("4. %20.d, %20.1d, %20.2d, %20.3d, %20.4d, %20.5d, %20.10d, %20.20d, %20.50d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");

	result_o = printf("5. %-20.d, %-20.1d, %-20.2d, %- 20.3d, %- 20.4d, %- 20.5d, %- 20.10d, %- 20.20d, %-+ 20.50d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("5. %-20.d, %-20.1d, %-20.2d, %- 20.3d, %- 20.4d, %- 20.5d, %- 20.10d, %- 20.20d, %-+ 20.50d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");
	
	result_o = printf("6. % 20.d, % 20.1d, % 20.2d, % 20.3d, % 20.4d, % 20.5d, % 20.10d, % 20.20d, % 20.50d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("6. % 20.d, % 20.1d, % 20.2d, % 20.3d, % 20.4d, % 20.5d, % 20.10d, % 20.20d, % 20.50d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");

	result_o = printf("7. %-d, %-1d, %-2d, %-3d, %-4d, %-5d, %-10d, %-20d, %-50d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("7. %-d, %-1d, %-2d, %-3d, %-4d, %-5d, %-10d, %-20d, %-50d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");

	result_o = printf("8. % +-d, % +-1d, % +-2d, % +-3d, % +-4d, % +-5d, % +-10d, % +-20d, % +-50d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("8. % +-d, % +-1d, % +-2d, % +-3d, % +-4d, % +-5d, % +-10d, % +-20d, % +-50d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");

	result_o = printf("9. % +-.d, % +-.1d, % +-.2d, % +-.3d, % +-.4d, % +-.5d, % +-10.d, % +-20.d, % +-50.d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("9. % +-.d, % +-.1d, % +-.2d, % +-.3d, % +-.4d, % +-.5d, % +-10.d, % +-20.d, % +-50.d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");

	result_o = printf("10. % -d, % -1d, % -2d, % -3d, % -4d, % -5d, % -10d, % -20d, % -50d.", num, num, num, num, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("10. % -d, % -1d, % -2d, % -3d, % -4d, % -5d, % -10d, % -20d, % -50d.", num, num, num, num, num, num, num, num, num);
	printf("\n\n");
	*/
	printf("\n");
	printf("original printf return : %d\n", result_o);
	printf("ft_printf return       : %d\n", result_ft);

	ft_printf("\n----------ft_printf BONUS test end----------\n\n");
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
	ft_printf("\nft_printf\n");
	result_ft = ft_printf("char : %c, string : %s, addr : %p, nbr_d : %d, nbr_i : %i, nbr_u : %u, nbr_x : %x, nbr_X : %X\n", c, s, &c, num, num, num, num, num);
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
