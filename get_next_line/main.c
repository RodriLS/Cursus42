#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	int fd2;
	char *help;
	char *aux;
	int	i;

	fd = open("./test_no_nl", O_RDONLY);
	fd2 = open("./test2", O_RDONLY);
	help = "a";
	while(help != NULL)
	{
		i = 0;
		free(aux);
		help = get_next_line(fd);
		while (help != NULL && help != 0 && help[i] != 0)
		{
			write(1, help + i, 1);
			i++;
		}
		aux = help;
		/*free(aux);
		help = get_next_line(fd2);
		i = 0;
		while (help && help != 0 && help[i] != 0)
		{
			write(1, help + i, 1);
			i++;
		}
		aux = help;*/
	}
	free(help);
}
