/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:36:09 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/15 15:16:31 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

void	memset_test()
{
	int	i;
	int	array1[10];
	int	array2[10];

	memset(array1, 0, sizeof(array1));
	ft_memset(array2, 0, sizeof(array2));

	printf("\n-----memset test start-----\n");

	printf("original memset\n");
	i = 0;
	while (i < 10)
	{
		printf("array1, idx %d = %d\n", i, array1[i]);
		i++;
	}

	printf("\nft_memset\n");
	i = 0;
	while (i < 10)
	{
		printf("array2, idx %d = %d\n", i, array2[i]);
		i++;
	}

	printf("-----memset test end-----\n\n");
}

void	bzero_test()
{
	int	i;
	int	array1[10];
	int	array2[10];

	printf("-----bzero test start-----\n");
	
	printf("before\n");
	i = 0;
	while (i < 10)
	{
		array1[i] = (int)random();
		array2[i] = (int)random();
		i++;
	}

	i = 0;
	while (i < 10)
	{
		printf("array1, idx %d = %d\n", i, array1[i]);
		i++;
	}
	printf("\n");

	i = 0;
	while (i < 10)
	{
		printf("array2, idx %d = %d\n", i, array2[i]);
		i++;
	}

	bzero(array1, 40);
	ft_bzero(array2, 40);

	printf("\nafter : original bzero\n");
	i = 0;
	while (i < 10)
	{
		printf("array1, idx %d = %d\n", i, array1[i]);
		i++;
	}

	printf("\nafter : ft_bzero\n");
	i = 0;
	while (i < 10)
	{
		printf("array2, idx %d = %d\n", i, array2[i]);
		i++;
	}
	
	printf("-----bzero test end-----\n\n");
}

void	memcpy_test()
{
	char	str1[] = "abcdefghijklmn";
	char	str2[] = "abcdefghijklmn";
	char	str3[] = "12345";
	int		arr1[10];
	int		arr2[10];

	printf("-----memcpy test start-----\n");
	
	printf("original memcpy\n");
	printf("before : %s\n", str1);
	memcpy(str1, str3, 4);
	printf("after : %s\n", str1);

	printf("\nft_memcpy\n");
	printf("before : %s\n", str2);
	ft_memcpy(str2, str3, 4);
	printf("after : %s\n", str2);

	printf("-----memcpy test end-----\n");
}

void	memmove_test()
{
	char	str1[] = "abcdefghijklmn";
	int		arr1[10];
	int		arr2[10];

	printf("\n-----memmove test start-----\n");

	printf("before : %s\n", str1);	//string test
	ft_memmove(str1, str1 + 4, 3);
	//memmove(str1, str1 + 4, 3);
	printf("after : %s\n", str1);

	printf("\nbefore : ");	//integer test
	for (int i = 0; i < 10; i++)
	{
		arr1[i] = 0;
		arr2[i] = -667;
		printf("%d ", arr1[i]);
	}
	printf("\nafter : ");
	//ft_memmove(arr1, arr2, 2);
	memmove(arr1, arr2, 2);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	printf("\n-----memmove test end-----\n");
}

void	strchr_test()
{
	char *str = "welcome to woosekim evaluation!!@";

	printf("\n-----strchr test start-----\n");
	printf("original strchr : %s\n", strchr(str, 'w'));
	printf("ft_strchr       : %s\n", ft_strchr(str, 'w'));
	printf("-----strchr test end-----\n");
}

void	strrchr_test()
{
	char *str = "have a nice day!";

	printf("\n-----strrchr test start-----\n");
	printf("original strrchr : %s\n", strrchr(str, 0));
	printf("ft_strrchr       : %s\n", ft_strrchr(str, 0));
	printf("-----strrchr test end-----\n");
}

void	memchr_test()
{
	char	*str = "sweet dreams, my dear"; //21
	
	printf("\n-----memchr test start-----\n");
	printf("original memchr : %s\n", memchr(str, 0, 5));
	printf("ft_memchr       : %s\n", ft_memchr(str, 0, 5));
	printf("-----memchr test end-----\n");
}

void	memcmp_test()
{
	char	*str1 = "memcmp test";
	char	*str2 = "memcmp test";
	
	printf("\n-----memcmp test start-----\n");
	printf("original memcmp : %d\n", memcmp(str1, str2, 5));
	printf("ft_memcmp       : %d\n", ft_memcmp(str1, str2, 5));
	printf("-----memcmp test end-----\n");
}

void	strnstr_test()
{
	char	*str = "can you find this strings?";
	char	*to_find = "c";

	printf("\n-----strnstr test start-----\n");
	printf("original strnstr : %s\n", strnstr(str, to_find, 1));
	printf("ft_strnstr       : %s\n", ft_strnstr(str, to_find, 1));
	printf("-----strnstr test end-----\n");
}

int	main()
{
	memset_test();
	bzero_test();
	memcpy_test();
	memmove_test();
	strchr_test();
	strrchr_test();
	memchr_test();
	memcmp_test();
	strnstr_test();

	return (0);
}
