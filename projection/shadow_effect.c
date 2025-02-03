/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_effect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:16:15 by aelison           #+#    #+#             */
/*   Updated: 2025/01/29 16:34:47 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	check_sp(t_scene *s, t_sp *obj, t_vect *ref_pts, int color_ref)
{
	int		res;
	double	t;
	t_vect	point;
	t_ray	r;

	res = -1;
	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z);
	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts));
	if (ft_intersec_sp(obj, &r, &point, &t) == EXIT_SUCCESS)
	{
		if (vect_lenght(substraction(s->light->pos,
					*ref_pts)) > vect_lenght(substraction(s->light->pos,
					point)))
			res = gen_color(color_ref, s->amlight, 0, 0);
	}
	return (res);
}

int	ft_add_shadow(t_scene *s, t_maps *other, t_vect *ref_pts, int color_ref)
{
	int	val;

	val = -1;
	if (!s || !ref_pts || !other)
		return (val);
	while (other)
	{
		if (other->type == Sphere)
		{
			val = check_sp(s, other->struct_obj, ref_pts, color_ref);
			if (val != -1)
				return (val);
		}
		other = other->next;
	}
	return (-1);
}
