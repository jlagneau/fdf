/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/22 17:46:38 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_nbline(char *file)
{
	int			fd;
	int			ret;
	int			i;
	char		buff[1];

	i = 1;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buff, 1)))
	{
		if (*buff == '\n')
			i++;
	}
	close(fd);
	return (i);
}

static char		***arg_parsefilerow(int fd, char ***coord)
{
	int			ret;
	int			y;
	char		*line;

	y = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (NULL);
		coord[y] = ft_strsplit(line, 32);
		ft_strdel(&line);
		if (ret == 0)
		{
			coord[y + 1] = ft_strsplit(line, 32);
			break ;
		}
		y++;
	}
	return (coord);
}

char			***arg_getcoord(char *file)
{
	int			fd;
	char		***coord;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr_fd("\033[31mError :\033[0m [", 2);
		ft_putstr_fd(file, 2);
		ft_putendl_fd("] is not a file.", 2);
		print_usage();
		exit(EXIT_FAILURE);
	}
	if (!(coord = (char ***)ft_memalloc(sizeof(char **) * get_nbline(file))))
		return (NULL);
	coord = arg_parsefilerow(fd, coord);
	close(fd);
	return (coord);
}
