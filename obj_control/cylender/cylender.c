/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:48 by aelison           #+#    #+#             */
/*   Updated: 2025/01/28 14:14:28 by aelison          ###   ########.fr       */
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

int	ft_intersec_cy(t_cy *obj, t_ray *r, double *solution)
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
		*solution = get_racine(a, b, discr);
		if (*solution < 0 || ft_cy_limit(*solution, r, obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

double	lambertienne_cy(double coeff_refct, t_l *light, t_cy *obj, t_vect point)
{
	double	res;
	t_vect	v_light;
	t_vect	v_normal;
	double	scal;

	v_normal = init_vect(0.5, 0.5, 0.5);
	v_light = ft_normalize(substraction(obj->center, point));
	scal = scalaire(v_normal, v_light);
	if (scal < 0)
		scal = 0;
	res = coeff_refct * scal * light->bright;
	return (res);
}

int	exec_cy(t_scene *s, t_cy *obj, t_ray *r, t_vect wind)
{
	int		res;
	double	lambert;
	double	solution;
	t_vect	point;

	res = FALSE;
	if (ft_intersec_cy(obj, r, &solution) == EXIT_SUCCESS)
	{
		point = sum(r->origin, vect_dot_val(r->direction, solution));
		lambert = lambertienne_cy(COEFF_REFCT, s->light, obj, point);
		res = gen_color(obj->color.color, s->amlight, lambert, REFRACTION_AM);
		ft_put_pixel(s->mlx, wind.x, wind.y, res);
	}
	return (res);
}
