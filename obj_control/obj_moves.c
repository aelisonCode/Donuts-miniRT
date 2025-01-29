/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:39:16 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 15:59:13 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/struct.h"

void	ft_translation(t_vect *point, int move, double incr)
{
	if (!point)
		return ;
	if (move == UP)
		point->y += incr;
	else if (move == DOWN)
		point->y -= incr;
	else if (move == LEFT)
		point->x -= incr;
	else if (move == RIGHT)
		point->x += incr;
	else if (move == SCALE_UP)
		point->z += incr;
	else if (move == SCALE_DOWN)
		point->z -= incr;
}

void	ft_scale(double *value, int move, double incr)
{
	if (!value)
		return ;
	if (move == SCALE_UP)
		*value += incr;
	else if (move == SCALE_DOWN)
		*value -= incr;
}
