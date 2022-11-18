/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:36:09 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/18 16:37:31 by woosekim         ###   ########.fr       */
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
	char	*str1 = "abcdefgh";
	char	*str2 = "zxcvbb";
	
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

void	isalpha_test()
{
	int	c[5];

	c[0] = 'a';
	c[1] = 'B';
	c[2] = '@';
	c[3] = -1;
	c[4] = 0;
	
	printf("\n-----isalpha test start-----\n");
	for (int i = 0; i < 5; i++)
	{
		printf("original isalpha : %d\n", isalpha(c[i]));
		printf("ft_isalpha       : %d\n", ft_isalpha(c[i]));
		if (i != 4)
			printf("\n");
	}
	printf("-----isalpha test end-----\n");
}

void	isdigit_test()
{
	int	c[5];

	c[0] = '0';
	c[1] = '4';
	c[2] = '9';
	c[3] = -1;
	c[4] = 0;
	
	printf("\n-----isdigit test start-----\n");
	for (int i = 0; i < 5; i++)
	{
		printf("original isdigit : %d\n", isdigit(c[i]));
		printf("ft_isdigit       : %d\n", ft_isdigit(c[i]));
		if (i != 4)
			printf("\n");
	}
	printf("-----isdigit test end-----\n");
}

void	isalnum_test()
{
	int	c[5];

	c[0] = '0';
	c[1] = 'E';
	c[2] = 'a';
	c[3] = -1;
	c[4] = 0;
	
	printf("\n-----isalnum test start-----\n");
	for (int i = 0; i < 5; i++)
	{
		printf("original isalnum : %d\n", isalnum(c[i]));
		printf("ft_isalnum       : %d\n", ft_isalnum(c[i]));
		if (i != 4)
			printf("\n");
	}
	printf("-----isalnum test end-----\n");
}

void	isascii_test()
{
	int	c[5];

	c[0] = '0';
	c[1] = 'E';
	c[2] = 'a';
	c[3] = -1;
	c[4] = 0;
	
	printf("\n-----isascii test start-----\n");
	for (int i = 0; i < 5; i++)
	{
		printf("original isascii : %d\n", isascii(c[i]));
		printf("ft_isascii       : %d\n", ft_isascii(c[i]));
		if (i != 4)
			printf("\n");
	}
	printf("-----isascii test end-----\n");
}

void	isprint_test()
{
	int	c[5];

	c[0] = '0';
	c[1] = 'E';
	c[2] = 'a';
	c[3] = -1;
	c[4] = 0;
	
	printf("\n-----isprint test start-----\n");
	for (int i = 0; i < 5; i++)
	{
		printf("original isprint : %d\n", isprint(c[i]));
		printf("ft_isprint       : %d\n", ft_isprint(c[i]));
		if (i != 4)
			printf("\n");
	}
	printf("-----isprint test end-----\n");
}

void	strlen_test()
{
	char *str = "i love libft!";

	printf("\n-----strlen test start-----\n");

	printf("original strlen : %lu\n", strlen(str));
	printf("ft_strlen       : %lu\n", ft_strlen(str));

	printf("-----strlen test start-----\n");
}

void	toupper_test()
{
	char	c = 'a';
	printf("\n-----toupper test start-----\n");

	printf("original toupper : %c\n", toupper(c));
	printf("ft_toupper       : %c\n", ft_toupper(c));

	printf("-----toupper test end-----\n");
}

void	tolower_test()
{
	char	c = 'A';
	printf("\n-----tolower test start-----\n");

	printf("original tolower : %c\n", tolower(c));
	printf("ft_tolower       : %c\n", ft_tolower(c));

	printf("-----tolower test end-----\n");
}

void	atoi_test()
{
	char	str[] = "    \t\n \t   \t   -0";

	printf("\n-----atoi test start-----\n");

	printf("original atoi : %d\n", atoi(str));
	printf("ft_atoi       : %d\n", ft_atoi(str));

	printf("-----atoi test end-----\n");
}

void	strlcpy_test()
{
	char	str1[100];
	char	str2[100];
	char	*str3 = "strlcpy strlcpy strlcpy test test test";
	
	printf("\n-----strlcpy test start-----\n");

	printf("original strlcpy : %lu, %s\n", strlcpy(str1, str3, 50), str1);
	printf("ft_strlcpy       : %lu, %s\n", ft_strlcpy(str2, str3, 50), str2);
	
	printf("-----strlcpy test end-----\n");
}

void	strlcat_test()
{
	char	str1[100] = "str1 strings + ";			//15
	char	str2[100] = "str2 strings + ";			//15
	char	*str3 = "strlcat strlcat test test";	//25
	
	printf("\n-----strlcat test start-----\n");

	printf("original strlcat : %lu, %s\n", strlcat(str1, str3, 41), str1);
	printf("ft_strlcat       : %lu, %s\n", ft_strlcat(str2, str3, 41), str2);

	printf("-----strlcat test end-----\n");
}

void	strdup_test()
{
	char	*str = "string duplicate test";
	char	*str_dup1;
	char	*str_dup2;

	printf("\n-----strdup test start-----\n");

	str_dup1 = strdup(str);
	str_dup2 = ft_strdup(str);

	printf("original strdup : %s\n", str_dup1);
	printf("ft_strdup       : %s\n", str_dup2);

	printf("-----strdup test end-----\n");

	free(str_dup1);
	free(str_dup2);
}

void	calloc_test()
{
	char	*p1;
	char	*p2;
	int		count = 10;

	printf("\n-----calloc test start-----\n");

	printf("original calloc\n");
	p1 = (char *)calloc(count, sizeof(char));
	for(int	i = 0; i < count; i++)
	{
		printf("%d", p1[i]);
		if (i != count - 1)
			printf(", ");
	}

	printf("\n\noriginal calloc input value\n");
	p1 = (char *)calloc(count, sizeof(char));
	for(int	i = 0; i < count; i++)
	{
		p1[i] = 127;
		printf("%d", p1[i]);
		if (i != count - 1)
			printf(", ");
	}

	printf("\n\nft_calloc\n");
	p2 = (char *)ft_calloc(count, sizeof(char));
	for(int	i = 0; i < count; i++)
	{
		printf("%d", p2[i]);
		if (i != count - 1)
			printf(", ");
	}

	printf("\n\nft_calloc input value\n");
	p2 = (char *)ft_calloc(count, sizeof(char));
	for(int	i = 0; i < count; i++)
	{
		p2[i] = 127;
		printf("%d", p2[i]);
		if (i != count - 1)
			printf(", ");
	}

	printf("\n-----calloc test end-----\n");

	free(p1);
	free(p2);
}

void	ft_substr_test()
{
	char			*str = "abc@dfad@fdga@010204";
	unsigned int	start = '@';
	char			*substr;
	size_t			len = 100000;

	printf("\n-----ft_substr test start-----\n");

	printf("original str : %s\n", str);
	printf("start        : %c\n", start);

	substr = ft_substr(str, start, len);
	printf("substr       : %s\n", substr);
	
	printf("-----ft_substr test end-----\n");

	free(substr);
}

void	ft_strjoin_test()
{
	char	*str1 = "zxcvzjoifjsdofajsdiofjasofjasiodfja + \\";
	char	*str2 = "zxcmvlzjxcfidjfoaisdjfoaisjdfalisdjfaiojfosijfoaisjdfoajsdfiojasdoifjaosidfjaoisdjfa";
	char	*strjoin;

	printf("\n-----ft_strjoin test start-----\n");

	printf("str1    : %s\n", str1);
	printf("str2    : %s\n", str2);

	strjoin = ft_strjoin(str1, str2);
	printf("strjoin : %s\n", strjoin);

	printf("-----ft_strjoin test end-----\n");

	free(strjoin);
}

void	ft_strtrim_test()
{
	char	*s1 = "abcd";
	char	*set = "bcaaaabbcc&*^$";
	char	*strtrim;

	printf("\n-----ft_strtrim test start-----\n");

	strtrim = ft_strtrim(s1, set);
	printf("s1      : %s\n", s1);
	printf("set     : %s\n", set);	
	printf("strtrim : %s\n", strtrim);

	printf("-----ft_strtrim test end-----\n");

	free(strtrim);
}

void	ft_split_test()
{
	char	*str = "\\ lostark overwatch2 leagueoflegends bigjaemi \\";
	char	c = 0;
	char	**split;

	printf("\n-----ft_split test start-----\n");

	printf("str      : %s\n", str);
	printf("word     : %c\n\n", c);	
	split = ft_split(str, c);
	for(int i = 0; i < 2; i++)
		printf("row %d    : %s\n", i, split[i]);
		
	printf("-----ft_split test end-----\n");

	free(split);
}

void	ft_itoa_test()
{
	int		n[11] = {-2147483648, -10008, -100, -10, -1, 0, 1, 10, 100, 10008, 2147483647};
	char	*str[11];

	printf("\n-----ft_itoa test start-----\n");
	
	for (int i = 0; i < 11; i++)
		str[i] = ft_itoa(n[i]);
	for (int i = 0; i < 11; i++)
	{
		printf("integer n[%d] : %d\n", i, n[i]);
		printf("string  n[%d] : %s\n", i, str[i]);
		if (i != 10)
			printf("\n");
	}

	printf("-----ft_itoa test end-----\n");

	for (int i = 0; i < 11; i++)
		free(str[i]);
}

char	f_ft_strmapi(unsigned int i, char c)
{
	c = ft_toupper(c);
	
	return (c);
}

void	ft_strmapi_test()
{
	char	*str1 = "abcdefghi9182847@!#";
	char	*str2;

	printf("\n-----ft_strmapi test start-----\n");
	
	printf("before : %s\n", str1);
	str2 = ft_strmapi(str1, f_ft_strmapi);
	printf("after  : %s\n", str2);

	printf("-----ft_strmapi test end-----\n");

	free(str2);
}

void	f_ft_striteri(unsigned int i, char *str)
{
	str[i] = ft_tolower(str[i]);
}

void	ft_striteri_test()
{
	char	str[] = "ABCDEFG684897!@#!@$!";

	printf("\n-----ft_striteri test start-----\n");
	
	printf("before : %s\n", str);
	ft_striteri(str, f_ft_striteri);
	printf("after  : %s\n", str);

	printf("-----ft_striteri test end-----\n");	
}

void	ft_putchar_fd_test()
{
	char	c = '@';

	printf("\n-----ft_putchar_fd test start-----\n");

	ft_putchar_fd(c, 1);

	printf("\n-----ft_putchar_fd test end-----\n");	
}

void	ft_putstr_fd_test()
{
	char	*str = "can you print this strings?";

	printf("\n-----ft_putstr_fd test start-----\n");

	ft_putstr_fd(str, 1);

	printf("\n-----ft_putstr_fd test end-----\n");	
}

void	ft_putendl_fd_test()
{
	char	*str = "can you print this strings with newline?";

	printf("\n-----ft_putendl_fd test start-----\n");

	ft_putendl_fd(str, 1);

	printf("\n-----ft_putendl_fd test end-----\n");
}

void	ft_putnbr_fd_test()
{
	int	n = -2147483648;

	printf("\n-----ft_putnbr_fd test start-----\n");

	ft_putnbr_fd(n, 1);

	printf("\n-----ft_putnbr_fd test end-----\n");
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
	isalpha_test();
	isdigit_test();
	isalnum_test();
	isascii_test();
	isprint_test();
	strlen_test();
	toupper_test();
	tolower_test();
	atoi_test();
	strlcpy_test();
	strlcat_test();
	strdup_test();
	calloc_test();
	ft_substr_test();
	ft_strjoin_test();
	ft_strtrim_test();
	ft_split_test();
	ft_itoa_test();
	ft_strmapi_test();
	ft_striteri_test();
	ft_putchar_fd_test();
	ft_putstr_fd_test();
	ft_putendl_fd_test();
	ft_putnbr_fd_test();
	
	return (0);
}
