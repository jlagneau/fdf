/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:27:05 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/22 17:27:24 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				put_pixel(int x, int y, int c, t_env *e)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (c & 0xFF0000) >> 16;
	g = (c & 0x00FF00) >> 8;
	b = (c & 0x0000FF);
	if (x <= WIDTH && y <= HEIGHT && x > 0 && y > 0)
	{
		e->data[y * e->sl + x * e->bpp / 8] = b;
		e->data[y * e->sl + x * e->bpp / 8 + 1] = g;
		e->data[y * e->sl + x * e->bpp / 8 + 2] = r;
	}
}
