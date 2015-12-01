/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/22 17:25:58 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		event_loop_stop(t_env *e)
{
	if (!(mlx_destroy_image(e->mlx, e->img)))
		return (EXIT_FAILURE);
	if (!(mlx_destroy_window(e->mlx, e->win)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				event_keyboard_handler(int k, t_env *e)
{
	if (k == ESCAPE_KEY)
		exit(event_loop_stop(e));
	if (k == ENTER_KEY)
		switch_perspective(e);
	draw(e);
	return (EXIT_SUCCESS);
}

int				event_mouse_handler(int button, int x, int y, t_env *e)
{
	(void)e;
	(void)x;
	(void)y;
	(void)button;
	return (EXIT_SUCCESS);
}

int				event_expose_handler(t_env *e)
{
	draw(e);
	return (EXIT_SUCCESS);
}
