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

void	ft_translation(t_vect *point, int move)
{
	if (!point)
		return ;
	if (move == UP)
		point->y++;
	else if (move == DOWN)
		point->y--;
	else if (move == LEFT)
		point->x--;
	else if (move == RIGHT)
		point->x++;
}

void	ft_scale(double *value, int move)
{
	double	tmp;

	if (!value)
		return ;
	tmp = 0.5;
	if (move == SCALE_UP)
		*value += tmp;
	if (move == SCALE_DOWN)
		*value -= tmp;
}
