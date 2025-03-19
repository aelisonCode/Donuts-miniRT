/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_effect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:16:15 by aelison           #+#    #+#             */
/*   Updated: 2025/02/27 08:23:45 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	ft_exec_obj(t_scene *s, t_ray *ogn, t_maps *do_block)
{
	int		val;
	t_vect	solution;
	t_ray	shadow_ray;

	val = FALSE;
	solution = compute_intersec_pts(ogn, s->tmp_dist);
	shadow_ray.origin = init_vect(solution.x, solution.y, solution.z);
	shadow_ray.direction = ft_normalize(substraction(s->light->pos, solution));
	if (do_block->type == Sphere)
		val = check_sp(s, do_block->struct_obj, &shadow_ray);
	if (do_block->type == Plane)
		val = check_pl(s, do_block->struct_obj, &shadow_ray);
	if (do_block->type == Cylinder)
		val = check_cy(s, do_block->struct_obj, &shadow_ray);
	return (val);
}

int	ft_is_a_shadow(t_scene *s, t_maps *to_check, t_ray *origin)
{
	int		val;
	t_maps	*tmp;

	val = FALSE;
	if (!s || !to_check || !origin)
		return (val);
	tmp = s->world;
	while (tmp)
	{
		if (to_check->id != tmp->id)
		{
			val = ft_exec_obj(s, origin, tmp);
			if (val == TRUE)
				return (val);
		}
		tmp = tmp->next;
	}
	return (val);
}
