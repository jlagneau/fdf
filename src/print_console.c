/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_console.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/18 12:29:47 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_usage(void)
{
	ft_putendl("\033[31mUsage :\033[0m ./fdf [-dh] [filename]");
	ft_putendl("\t-d\tPrint debug");
	ft_putendl("\t-h\tPrint this help message");
	exit(0);
}

void	print_debug(char ***coord)
{
	int		x;
	int		y;

	y = 0;
	while (coord[y])
	{
		x = 0;
		while (coord[y][x])
		{
			if (ft_strlen(coord[y][x]) == 2)
				ft_putstr(coord[y][x]);
			else
			{
				ft_putchar(' ');
				ft_putstr(coord[y][x]);
			}
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
