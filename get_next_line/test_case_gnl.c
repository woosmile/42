#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	
	printf("\n-----GET NEXT LINE TEST START-----\n\n");

	printf("%s\n", get_next_line(fd));

	printf("\n\n-----GET NEXT LINE TEST END-----\n");

	return (0);
}