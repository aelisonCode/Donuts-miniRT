/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:48 by aelison           #+#    #+#             */
/*   Updated: 2025/01/30 15:09:03 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

/*
 * NOT WORKING
 * NEED TO BE CHECK, RE DO ????
 */

static int	ft_cy_limit(int sol, t_ray *r, t_cy *obj)
{
	t_vect	intersect;
	double	projection;

	intersect = sum(r->origin, vect_dot_val(r->direction, sol));
	projection = scalaire(substraction(intersect, obj->center), obj->direction);
	if (projection < 0 || projection > obj->height)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_intersec_cy(t_cy *obj, t_ray *r, t_vect *solution)
{
	double	a;
	double	b;
	double	c;
	t_vect	dist;
	double	discr;

	dist = substraction(r->origin, obj->center);
	a = scalaire(r->direction, r->direction) - pow(scalaire(r->direction,
				obj->direction), 2);
	b = 2 * (scalaire(r->direction, dist) - (scalaire(r->direction,
					obj->direction)) * (scalaire(dist, obj->direction)));
	c = scalaire(dist, dist) - pow(scalaire(dist, obj->direction), 2)
		- (obj->radius * obj->radius);
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (EXIT_FAILURE);
	if (solution != NULL)
	{
		if (get_racine(a, b, discr) < 0)
			return (EXIT_FAILURE);
		if (ft_cy_limit(get_racine(a, b, discr), r, obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		*solution = compute_intersec_pts(r, get_racine(a, b, discr));
	}
	return (EXIT_SUCCESS);
}

/*lambertieenne cylender
 * is point on the side ?
 * is point on surface ?
 */
double	lambertienne_cy(double coeff_refct, t_l *light, t_cy *obj, t_vect point)
{
	double	res;
	t_vect	v_light;
	t_vect	v_normal;
	double	scal;

	v_normal = ft_normalize(substraction(point, obj->center));
	v_light = ft_normalize(substraction(light->pos, point));
	scal = scalaire(v_normal, v_light);
	if (scal < 0)
		scal = 0;
	res = coeff_refct * scal * light->bright;
	return (res);
}

int	get_cy_color(t_scene *s, t_maps *curr, t_vect *point)
{
	int		res;
	int		shadow;
	double	lambert;
	t_sp	*sphere;

	sphere = curr->struct_obj;
	lambert = lambertienne_cy(COEFF_REFCT, s->light, curr->struct_obj, *point);
	res = gen_color(sphere->color.color, s->amlight, lambert, REFRACTION_AM);
	shadow = ft_add_shadow(s, curr->next, point, sphere->color.color);
	if (shadow != -1)
		res = shadow;
	return (res);
}

int	exec_cy(t_scene *s, t_maps *curr, t_ray *r, t_vect wind)
{
	int		res;
	int		color;
	t_vect	solution;

	res = EXIT_FAILURE;
	(void)wind;
	if (ft_intersec_cy(curr->struct_obj, r, &solution) == EXIT_SUCCESS)
	{
		res = EXIT_SUCCESS;
		color = get_cy_color(s, curr, &solution);
		cmp_dist(s, &solution, color);
		ft_put_pixel(s->mlx, wind.x, wind.y, color);
	}
	return (res);
}
