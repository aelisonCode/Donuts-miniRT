/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:47 by aelison           #+#    #+#             */
/*   Updated: 2025/02/27 08:28:26 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	ft_check_obstacle(t_vect goal, t_vect p1, t_vect p2)
{
	t_vect	dist1;
	t_vect	dist2;

	dist1 = substraction(goal, p1);
	dist2 = substraction(goal, p2);
	if (scalaire(dist1, dist2) > 0)
	{
		if (vect_length(dist1) > vect_length(dist2))
			return (TRUE);
	}
	return (FALSE);
}

int	check_sp(t_scene *s, t_sp *do_block, t_ray *shadow_ray)
{
	int		val;
	double	t;
	t_vect	block_sol;
	t_vect	check_sol;

	val = FALSE;
	if (ft_intersec_sp(do_block, shadow_ray, &t) == EXIT_SUCCESS)
	{
		block_sol = compute_intersec_pts(shadow_ray, t);
		check_sol = shadow_ray->origin;
		val = ft_check_obstacle(s->light->pos, check_sol, block_sol);
	}
	return (val);
}

int	check_pl(t_scene *s, t_pl *do_block, t_ray *shadow_ray)
{
	int		val;
	double	t;
	t_vect	block_sol;
	t_vect	check_sol;

	val = FALSE;
	if (ft_intersec_pl(do_block, shadow_ray, &t) == EXIT_SUCCESS)
	{
		block_sol = compute_intersec_pts(shadow_ray, t);
		check_sol = shadow_ray->origin;
		val = ft_check_obstacle(s->light->pos, check_sol, block_sol);
	}
	return (val);
}

int	check_cy(t_scene *s, t_cy *do_block, t_ray *shadow_ray)
{
	int		val;
	double	t;
	t_vect	block_sol;
	t_vect	check_sol;

	val = FALSE;
	if (ft_intersec_cy(do_block, shadow_ray, &t) == EXIT_SUCCESS)
	{
		block_sol = compute_intersec_pts(shadow_ray, t);
		check_sol = shadow_ray->origin;
		val = ft_check_obstacle(s->light->pos, check_sol, block_sol);
	}
	return (val);
}
