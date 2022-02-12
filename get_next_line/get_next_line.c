#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static  t_list_fd *storage;

static void	*ft_freeunusednodes(int fd, int mode)//mode 0 to mantein the last node of the fd, mode 1 to removve every node of the fd
{
	t_list_fd	*aux;
	t_list_fd	*aux_prev;
	t_list_fd	*aux_next_fd;
	t_list_fd	*aux_next;
	int			first_fd;

	first_fd = 1;
	aux = storage;
	aux_prev = storage;
	while (aux->fd != fd)
	{
		first_fd = 0;
		if (aux != storage)
			aux_prev = aux_prev->next_fd;
		aux = aux->next_fd;
	}
	aux_next_fd = aux->next_fd;
	while (aux && (aux->next || mode))
	{
		aux_next = aux->next;
		free(aux->content);
		free(aux);
		aux = aux_next;	
	}
	if (mode)
		aux = aux_next_fd;
	if (first_fd)
		storage = aux;
	else
		aux_prev->next_fd = aux;
	if (!mode)
		aux->next_fd = aux_next_fd;		
	return (NULL);
}

static t_list_fd        *ft_newlstfd(int fd)
{
	t_list_fd       *actual;

	actual = malloc(sizeof(t_list_fd));
	actual->next = NULL;
	actual->next_fd = NULL;
	actual->init = 0;
	actual->content = malloc(BUFFER_SIZE);
	actual->fd = fd;
	return (actual);
}

static char     *ft_getline(int fd, int len, t_list_fd *actual)
{
	char    *res;
	int     i;
	int	offset;

	//printf("%i\n", len);
	i = 0;
	actual = storage;
	res = malloc(len + 1);
	while (actual->fd != fd)
		actual = actual->next_fd;
	offset = actual->init;
	while (i < len)
	{
		if (offset + i != 0 && ((offset + i) % BUFFER_SIZE) == 0)
			actual = actual->next;
		res[i] = actual->content[(offset + i) % BUFFER_SIZE];
		i++;
	}
	res[i] = 0;
	actual->init = (offset + i) % BUFFER_SIZE;
	ft_freeunusednodes(fd, 0);
	//system("a.out leaks");
	return (res);
}



char *get_next_line(int fd)
{
	t_list_fd       *actual;
	int             len;
	int             i;
	int		chrs_readed;

	i = 0;
	if (!storage)
		storage = ft_newlstfd(fd);
	actual = storage;
	while (actual->fd != fd && actual->next_fd)
		actual = actual->next_fd;
	if (actual->fd != fd)
	{
		actual->next_fd = ft_newlstfd(fd);
		actual = actual->next_fd;
	}
	len = 0;
	//char c;
	while (len <= 0) //len > 0 means that we have reached a \n
	{
		if (actual->init == 0)
		{	chrs_readed = read(fd,actual->content, BUFFER_SIZE);
			if (chrs_readed <= 0)
				return (ft_freeunusednodes(fd, 1));
		}
		else
			chrs_readed = BUFFER_SIZE;
		i = actual->init;
		while (i < chrs_readed && actual->content[i] != '\n' && actual->content[i])
			i++;
		if (i < chrs_readed && actual->content[i] == '\n')
			i++;
		len = (len - i + actual->init) * (((i == chrs_readed) * 2) - 1); //update the len adding the total number of chars we have read and changing its sign if we have found a \n
		if (len < 0) 
		{
			actual->next = ft_newlstfd(fd);
			actual = actual->next;
		}
/*		c = 98 + len;
		write(1, &c, 1);
		c = 38 + chrs_readed;
		write(1, &c, 1);
		c = 38 + i;
		write(1, &c, 1);
*/	}
	return (ft_getline(fd, len, actual));
}
