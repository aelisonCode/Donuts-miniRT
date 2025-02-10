/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:47 by aelison           #+#    #+#             */
/*   Updated: 2025/02/07 11:16:43 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	gen_shadow(t_a *amlight, t_maps *target)
{
	t_sp	*tmp_sp;
	t_pl	*tmp_pl;
	t_cy	*tmp_cy;
	int		res;

	if (!amlight || !target)
		return (-1);
	res = -1;
	if (target->type == Sphere)
	{
		tmp_sp = target->struct_obj;
		res = gen_color(tmp_sp->color.color, amlight, EPSILON);
	}
	else if (target->type == Plane)
	{
		tmp_pl = target->struct_obj;
		res = gen_color(tmp_pl->color.color, amlight, EPSILON);
	}
	else if (target->type == Cylinder)
	{
		tmp_cy = target->struct_obj;
		res = gen_color(tmp_cy->color.color, amlight, EPSILON);
	}
	return (res);
}

int	check_sp(t_scene *s, t_sp *obj, t_vect *ref_pts, t_maps *target)
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
			res = gen_shadow(s->amlight, target);
	}
	return (res);
}

int	check_pl(t_scene *s, t_pl *obj, t_vect *ref_pts, t_maps *target)
{
	int		res;
	double	t;
	t_vect	point;
	t_ray	r;

	res = -1;
	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z);
	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts));
	if (ft_intersec_pl(obj, &r, &point, &t) == EXIT_SUCCESS)
	{
		if (vect_lenght(substraction(s->light->pos,
					*ref_pts)) > vect_lenght(substraction(s->light->pos,
					point)))
			res = gen_shadow(s->amlight, target);
	}
	return (res);
}

int	check_cy(t_scene *s, t_cy *obj, t_vect *ref_pts, t_maps *target)
{
	int		res;
	double	t;
	t_vect	point;
	t_ray	r;

	res = -1;
	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z);
	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts));
	if (ft_intersec_cy(obj, &r, &point, &t) == EXIT_SUCCESS)
	{
		if (vect_lenght(substraction(s->light->pos,
					*ref_pts)) > vect_lenght(substraction(s->light->pos,
					point)))
			res = gen_shadow(s->amlight, target);
	}
	return (res);
}
