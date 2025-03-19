/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:03:39 by aelison           #+#    #+#             */
/*   Updated: 2025/02/24 14:13:51 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

static int	compute_pl(t_cy *ref, t_pl *obj, t_ray *r)
{
	double	t;
	t_vect	solution;

	if (ft_intersec_pl(obj, r, &t) == EXIT_SUCCESS)
	{
		solution = compute_intersec_pts(r, t);
		if (vect_length(substraction(solution, obj->point)) <= ref->radius)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_cy_limit(t_cy *obj, t_ray *r)
{
	t_pl	edge_top;
	t_pl	edge_bot;
	t_vect	axe_negatif;

	axe_negatif = vect_dot_val(obj->direction, -1);
	edge_top.point = sum(obj->center, vect_dot_val(obj->direction, obj->height
				/ 2));
	edge_top.direction = init_vect(obj->direction.x, obj->direction.y,
			obj->direction.z);
	edge_bot.point = sum(obj->center, vect_dot_val(axe_negatif, obj->height
				/ 2));
	edge_bot.direction = init_vect(axe_negatif.x, axe_negatif.y, axe_negatif.z);
	if (compute_pl(obj, &edge_top, r) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (compute_pl(obj, &edge_bot, r) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	is_in_limit(t_cy *obj, t_vect *solution)
{
	double	project_height;

	project_height = scalaire(substraction(*solution, obj->center),
			obj->direction);
	if (project_height >= obj->height / 2)
		return (EXIT_SUCCESS);
	if (project_height <= (obj->height / 2) * -1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	compute_edge(t_cy *obj, t_ray *r, t_vect *solution)
{
	if (!obj || !r)
		return (-1);
	if (is_in_limit(obj, solution) == EXIT_SUCCESS)
		return (ft_cy_limit(obj, r));
	return (-1);
}
