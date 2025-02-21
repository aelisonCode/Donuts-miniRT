/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:07:48 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 15:47:42 by mravelon         ###   ########.fr       */
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

int	get_cy_color(t_scene *s, t_maps *curr, t_vect *point, double lambert)
{
	int		res;
	int		shadow;
	t_cy	*cylinder;

	cylinder = curr->struct_obj;
	res = gen_color(cylinder->color.color, s->amlight, lambert);
	shadow = ft_add_shadow(s, curr, point);
	if (shadow != -1)
		res = shadow;
	return (res);
}

int	exec_cy(t_scene *s, t_maps *curr, t_ray *r)
{
	t_cy	*obj;
	double	t;
	/* double	lambert; */
	t_vect	solution;
	/* t_vect	v_normal; */

	if (!s || !curr || !r)
		return (EXIT_FAILURE);
	obj = curr->struct_obj;
	if (ft_intersec_cy(obj, r, &solution, &t) == EXIT_SUCCESS)
	{
		/* v_normal = ft_normal_cy(r, obj, t, solution); */
		/* lambert = lambertienne_cy(v_normal, s->light, solution); */
		/* curr->color = get_cy_color(s, curr, &solution, lambert); */
		curr->color = obj->color.color;
		cmp_dist(s, t, curr->color);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
