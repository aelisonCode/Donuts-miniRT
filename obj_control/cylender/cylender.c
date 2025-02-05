/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:48 by aelison           #+#    #+#             */
/*   Updated: 2025/02/04 08:57:06 by aelison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

static int	ft_cy_limit(t_cy *obj, t_vect *solution)
{
	if (vect_lenght(substraction(obj->center, *solution)) > obj->height / 2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_intersec_cy(t_cy *obj, t_ray *r, t_vect *solution, double *t)
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
		*t = get_racine(a, b, discr);
		if (*t < 0)
			return (EXIT_FAILURE);
		*solution = compute_intersec_pts(r, *t);
		if (ft_cy_limit(obj, solution) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*lambertieenne cylender
 * is point on the side ?
 * is point on surface ?
 */

static t_vect	ft_normal_cy(t_ray *r, t_cy *obj, double t, t_vect point)
{
	double	closest_pts;
	t_vect	res;

	closest_pts = scalaire(r->direction, vect_dot_val(obj->direction, t));
	closest_pts = closest_pts + scalaire(substraction(r->origin, obj->center), obj->direction);
	res = substraction(point, obj->center);
	res = ft_normalize(substraction(res, vect_dot_val(obj->direction,closest_pts)));
	return (res);
}

double	lambertienne_cy(t_vect v_normal, t_l *light, t_vect point)
{
	double	res;
	t_vect	v_light;
	double	scal;

	v_light = ft_normalize(substraction(light->pos, point));
	scal = scalaire(v_normal, v_light);
	if (scal < 0)
		scal = 0;
	res = COEFF_REFCT * scal * light->bright;
	return (res);
}

int	get_cy_color(t_scene *s, t_maps *curr, t_vect *point, double lambert)
{
	int		res;
	int		shadow;
	t_cy	*cylender;

	cylender = curr->struct_obj;
	res = gen_color(cylender->color.color, s->amlight, lambert, REFRACTION_AM);
	shadow = ft_add_shadow(s, curr, point);
	if (shadow != -1)
		res = shadow;
	return (res);
}

int	exec_cy(t_scene *s, t_maps *curr, t_ray *r)
{
	int		res;
	double	t;
	double	lambert;
	t_vect	normal;
	t_vect	solution;

	res = EXIT_FAILURE;
	if (ft_intersec_cy(curr->struct_obj, r, &solution, &t) == EXIT_SUCCESS)
	{
		res = EXIT_SUCCESS;
		normal = ft_normal_cy(r, curr->struct_obj, t, solution);
		lambert = lambertienne_cy(normal, s->light, solution);
		curr->color = get_cy_color(s, curr, &solution, lambert);
		cmp_dist(s, t, curr->color);
	}
	return (res);
}
