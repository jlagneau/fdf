/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/22 17:28:34 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			clear(t_env *e)
{
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, mlx_get_color_value(e->mlx, 0x000000), e);
			x++;
		}
		y++;
	}
}

static void			trace_line_assign(t_diff *d, t_coord *c1, t_coord *c2)
{
	d->x = c1->x;
	d->y = c1->y;
	d->dx = ABSOLUTE((c2->x - c1->x));
	d->dy = ABSOLUTE((c2->y - c1->y));
	d->incx = (c2->x < c1->x) ? -1 : 1;
	d->incy = (c2->y < c1->y) ? -1 : 1;
	d->err = (d->dx > d->dy) ? 2 * d->dy - d->dx : 2 * d->dx - d->dy;
	d->inc1 = (d->dx > d->dy) ? 2 * (d->dy - d->dx) : 2 * (d->dx - d->dy);
	d->inc2 = (d->dx > d->dy) ? 2 * d->dy : 2 * d->dx;
}

static void			trace_line(t_coord *c1, t_coord *c2, t_z *z, t_env *e)
{
	int				i;
	t_diff			d;

	trace_line_assign(&d, c1, c2);
	i = (d.dx > d.dy) ? d.dx : d.dy;
	while (i--)
	{
		if (d.err >= 0)
		{
			if (d.dx > d.dy)
				d.y += d.incy;
			else
				d.x += d.incx;
			d.err += d.inc1;
		}
		else
			d.err += d.inc2;
		if (d.dx > d.dy)
			d.x += d.incx;
		else
			d.y += d.incy;
		put_pixel(d.x, d.y, mlx_get_color_value(e->mlx, col(z->z1, z->z2)), e);
	}
}

static void			trace(int x, int y, t_env *e)
{
	t_coord			r1;
	t_coord			r2;
	t_z				z;

	z.z1 = ft_atoi(e->coord[y][x]);
	e->pers(x, y, z.z1, &r1);
	put_pixel(r1.x, r1.y, mlx_get_color_value(e->mlx, col(z.z1, z.z1)), e);
	if (e->coord[y + 1] && e->coord[y + 1][0] && e->coord[y + 1][x])
	{
		z.z2 = ft_atoi(e->coord[y + 1][x]);
		e->pers(x, y + 1, z.z2, &r2);
		trace_line(&r1, &r2, &z, e);
	}
	if (e->coord[y][x + 1])
	{
		z.z2 = ft_atoi(e->coord[y][x + 1]);
		e->pers(x + 1, y, z.z2, &r2);
		trace_line(&r1, &r2, &z, e);
	}
}

int					draw(t_env *e)
{
	int				x;
	int				y;

	y = 0;
	clear(e);
	while (e->coord[y])
	{
		x = 0;
		while (e->coord[y][x])
		{
			trace(x, y, e);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
