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

	//fd2 = open("", O_RDONLY);
	fd = open("./file", O_RDONLY);
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
		/*if(aux != NULL)
			free(aux);
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
