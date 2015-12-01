/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/22 18:26:29 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		col(int z1, int z2)
{
	if (z1 < z2)
		z1 = z2;
	if (z1 < 0)
		return (0x0000FF);
	else if (z1 == 0)
		return (0xFFFFFF);
	else if (z1 == 30)
		return (0x00FF00);
	else
		return (0xFF0000);
}
