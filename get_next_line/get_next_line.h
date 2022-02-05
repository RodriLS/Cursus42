/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:53:08 by rlopez-s          #+#    #+#             */
/*   Updated: 2022/01/28 20:24:58 by rlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>

typedef struct s_list_of_fd
{
	char			*content;
	int			init;
	int			fd;
	struct s_list_of_fd	*next_fd;
	struct s_list_of_fd	*next;
}					t_list_fd;

char *get_next_line(int fd);

#endif
