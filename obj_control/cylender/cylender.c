/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:48 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 15:50:11 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

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
		if (*solution < 0)
			return (EXIT_FAILURE);
		t_vect	intersect;
		double	projection;

		intersect = sum(r->origin, vect_dot_val(r->direction, *solution));
		projection = scalaire(substraction(intersect, obj->center), obj->direction);
		if (projection < 0 || projection > obj->height)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	exec_cy(t_scene *s, t_cy *obj, t_ray *r)
{
	int		res;
	double	solution;

	s++;
	res = 0X000000;
	if (ft_intersec_cy(obj, r, &solution) == EXIT_SUCCESS)
		res = 0X00FF00;
	return (res);
}
