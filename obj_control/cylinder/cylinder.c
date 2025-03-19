/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:48 by aelison           #+#    #+#             */
/*   Updated: 2025/02/25 14:08:58 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

t_vect	ft_normal_cy(t_ray *r, t_cy *obj, double t, t_vect point)
{
	double	closest_pts;
	t_vect	res;

	closest_pts = scalaire(r->direction, vect_dot_val(obj->direction, t));
	closest_pts = closest_pts + scalaire(substraction(r->origin, obj->center),
			obj->direction);
	res = substraction(point, obj->center);
	res = ft_normalize(substraction(res, vect_dot_val(obj->direction,
					closest_pts)));
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

int	exec_cy(t_scene *s, t_maps *curr, t_ray *r)
{
	double	t;

	if (!s || !curr || !r)
		return (EXIT_FAILURE);
	if (ft_intersec_cy(curr->struct_obj, r, &t) == EXIT_SUCCESS)
	{
		cmp_dist(s, curr, t);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
