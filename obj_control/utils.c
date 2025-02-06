/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:56:01 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 10:19:42 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	compute_intersec_pts(t_ray *r, double t)
{
	t_vect	result;

	result = sum(r->origin, vect_dot_val(r->direction, t));
	return (result);
}

int	cmp_dist(t_scene *s, double dist, int new_col)
{
	if (s->dist_curr == -1)
	{
		s->dist_curr = dist;
		s->color_to_put = new_col;
	}
	if (s->dist_curr >= dist)
	{
		s->dist_curr = dist;
		s->color_to_put = new_col;
	}
	return (EXIT_FAILURE);
}

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
	else if (move == Z_UP)
		point->z += incr;
	else if (move == Z_DOWN)
		point->z -= incr;
}
