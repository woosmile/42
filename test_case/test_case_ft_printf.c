#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

void	test()
{
	int	result_o = 0;
	int	result_ft = 0;

	char	c = '@';
	char	*s = "";
	int		num = 54651866;

	printf("\n----------ft_printf test start----------\n\n");

	result_o = printf("char : %c, string : %s, address : %p, nbr_i : %i, nbr_u : %u, nbr_d : %d, nbr_x : %x, nbr_X : %X, %% : %%.", c, s, s, num, num, num, num, num);
	printf("\n");
	result_ft = ft_printf("char : %c, string : %s, address : %p, nbr_i : %i, nbr_u : %u, nbr_d : %d, nbr_x : %x, nbr_X : %X, %% : %%.", c, s, s, num, num, num, num, num);
	
	/* nbr test */
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

	printf("\noriginal printf return : %d\n", result_o);
	printf("ft_printf return       : %d\n", result_ft);

	ft_printf("\n----------ft_printf test end----------\n\n");
}

int	main(void)
{
	test();

	return (0);
}
