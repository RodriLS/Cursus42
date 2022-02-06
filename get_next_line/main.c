#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *help;
	int	i;

	fd = open("./test", O_RDONLY);
	help = "a";
	while(help != NULL)
	{
		i = 0;
		help = get_next_line(fd);
		while (help != 0  && help[i] != 0)
		{
			write(1, help + i, 1);
			i++;
		}
	}
}
