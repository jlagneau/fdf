/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/21 19:58:41 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			switch_perspective(t_env *e)
{
	if (e->pers == &get_realcoord_para)
		e->pers = &get_realcoord_iso;
	else
		e->pers = &get_realcoord_para;
}

void			get_realcoord_para(int x, int y, int z, t_coord *coord)
{
	coord->x = (x + (-CTE1 * y)) * PAD + 250;
	coord->y = (y + ((-CTE1 / 2.0) * (z / 3))) * PAD + 200.0;
}

void			get_realcoord_iso(int x, int y, int z, t_coord *coord)
{
	coord->x = ((CTE1 * x) - (CTE2 * y)) * PAD + 300;
	coord->y = ((z * -0.1) + ((CTE1 / 2) * x) + ((CTE2 / 2) * y)) * PAD2 + 150;
}
