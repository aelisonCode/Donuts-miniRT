/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:56:01 by aelison           #+#    #+#             */
/*   Updated: 2025/02/13 11:44:14 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	compute_intersec_pts(t_ray *r, double t)
{
	t_vect	result;

	result = sum(r->origin, vect_dot_val(r->direction, t));
	result.x -= EPSILON;
	result.y -= EPSILON;
	result.z -= EPSILON;
	return (result);
}

int	cmp_dist(t_scene *s, t_maps *obj, double dist)
{
	if (s->nearest_obj == NULL)
	{
		s->nearest_obj = obj;
		s->tmp_dist = dist;
		return (EXIT_SUCCESS);
	}
	if (s->tmp_dist > dist)
	{
		s->nearest_obj = obj;
		s->tmp_dist = dist;
		return (EXIT_SUCCESS);
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
	else if (move == SCALE_UP)
		point->z += incr;
	else if (move == SCALE_DOWN)
		point->z -= incr;
}
