/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_effect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:16:15 by aelison           #+#    #+#             */
/*   Updated: 2025/02/07 13:45:01 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

double	double_abs(double x)
{
	if (x < 0)
		x = x * -1;
	return (x);
}

int	make_shadow(t_ray *r, t_vect *inter, t_sp *obj)
{
	double a;
	double b;
	double c;
	t_vect dist;
	double first;
	double delta;
	double d_one;
	double d_two;

	dist = substraction(r->origin, obj->center);
	a = scalaire(r->direction, r->direction);
	b = 2 * scalaire(r->direction, dist);
	c = scalaire(dist, dist) - pow(obj->radius, 2);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (EXIT_FAILURE);
	if (delta == 0)
		return (EXIT_SUCCESS);
	first = (inter->x - (r->origin.x)) / inter->x;
	d_one = ((-1 * b) + sqrt(delta)) / (2 * a);
	d_two = ((-1 * b) - sqrt(delta)) / (2 * a);
	d_one = round(d_one);
	d_two = round(d_two);
	if (first == d_one)
		return (EXIT_SUCCESS);
	else if (first == d_two)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

double	distance(t_vect o, t_vect d)
{
	double res;

	res = sqrt(pow(d.x - o.x, 2) + pow(d.y - o.y, 2) + pow(d.z - o.z, 2));
	return (res);
}

double ft_round(double s)
{
	double res;

	res = 0.0;
	if (s < 0.5 && s >= 0)
	{
		if (s == 0)
			res = 1;
		if (s >= 0 && s < 0.2)
			res = s + 0.8;
		if (s >= 0.2 && s < 0.3)
			res = s + 0.6;
		if (s >= 0.3 && s < 0.4)
			res = s + 0.4;
		if (s >= 0.4 && s < 0.5)
			res = s + 0.2;
	}
	else if (s > 0.5 && s <= 1)
	{
		if (s == 1)
			res = 0;
		if (s < 1 && s <= 0.9)
			res = s - 0.8;
		if (s < 0.9 && s >= 0.8)
			res = s - 0.6;
		if (s < 0.8 && s >= 0.7)
			res = s - 0.4;
		if (s < 0.7 && s >= 0.6)
			res = s - 0.2;
	}
	return (res);
}

double	shadow_intensity(t_vect *inter, t_vect *obj_inter, t_ray ray)
{
	double d_max;
	double d;
	double i;

	(void)obj_inter;
	d_max = distance(ray.origin, *inter);
	d = distance(*obj_inter, ray.origin);
	i = fmax(0, (1 - (d / d_max)));
	i = 1 - (1 / (1 + (0.01 * pow(d_max, 2))));
	return (i);
}

int	check_sp(t_scene *s, t_sp *obj, t_vect *ref_pts, t_maps *target, double lambert)
{
	int		res;
	double	t;
	t_vect	point;
	t_ray	r;
	double		shadow;
	t_sp	*tmp;

	res = -1;
	shadow = 0.0;
	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z);
	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts));
	if (ft_intersec_sp(obj, &r, &point, &t) == EXIT_SUCCESS)
	{
		if (vect_lenght(substraction(s->light->pos,
					*ref_pts)) > vect_lenght(substraction(s->light->pos,
					point)))
		{
			res = make_shadow(&r, ref_pts, target->struct_obj);
			if (res == EXIT_SUCCESS)
			{
				tmp = target->struct_obj;
				shadow = lambert * (1 - (shadow_intensity(ref_pts, &point, r)));
				res = gen_color(tmp->color.color, s->amlight, shadow, EPSILON);
			}
			else
				res = -1;
		}
	}
	return (res);
}

int	check_pl(t_scene *s, t_pl *obj, t_vect *ref_pts, t_maps *target)
{
	int		res;
	double	t;
	t_vect	point;
	t_ray	r;

	(void)target;
	res = -1;
	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z);
	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts));
	if (ft_intersec_pl(obj, &r, &point, &t) == EXIT_SUCCESS)
	{
		if (vect_lenght(substraction(s->light->pos,
					*ref_pts)) > vect_lenght(substraction(s->light->pos,
					point)))
			res = gen_color(obj->color.color, s->amlight, EPSILON, EPSILON);
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
		{
			res = gen_color(obj->color.color, s->amlight, EPSILON, EPSILON);
			if (target->type == Plane)
				return (res);
		}
	}
	return (res);
}

static int	ft_exec_obj(t_scene *s, t_maps *ptr, t_vect *ref_pts,
		t_maps *target, double lambert)
{
	int	val;

	val = -1;
	if (ptr->type == Sphere)
	{
		val = check_sp(s, ptr->struct_obj, ref_pts, target, lambert);
		if (val != -1)
			return (val);
	}
	if (ptr->type == Plane)
	{
		val = check_pl(s, ptr->struct_obj, ref_pts, target);
		if (val != -1)
			return (val);
	}
	if (ptr->type == Cylinder)
	{
		val = check_cy(s, ptr->struct_obj, ref_pts, target);
		if (val != -1)
			return (val);
	}
	return (val);
}

int	ft_add_shadow(t_scene *s, t_maps *target, t_vect *ref_pts, double lambert)
{
	int		val;
	t_maps	*tmp;

	val = -1;
	if (!s || !target || !ref_pts)
		return (val);
	tmp = s->world;
	while (tmp)
	{
		if (target->id != tmp->id)
		{
			val = ft_exec_obj(s, tmp, ref_pts, target, lambert);
			if (val != -1)
				return (val);
		}
		tmp = tmp->next;
	}
	return (val);
}
