/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:09:10 by aelison          #+#    #+#             */
/*   Updated: 2025/02/06 10:18:08 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_cy_event(t_scene *s, t_cy *obj, int keycode, double incr)
{
	if (s->do_rotation == FALSE)
	{
		if (keycode == LEFT || keycode == RIGHT || keycode == UP
			|| keycode == DOWN)
			ft_translation(&obj->center, keycode, incr);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_translation(&obj->center, keycode, -incr);
	}
	else if (s->do_rotation == TRUE)
	{
		if (keycode == LEFT || keycode == RIGHT || keycode == UP
			|| keycode == DOWN)
			ft_rotate(&obj->direction, keycode, 3);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_rotate(&obj->direction, keycode, 3);
	}
	if (keycode == SCALE_UP || keycode == SCALE_DOWN)
	{
		ft_scale(&obj->height, keycode, incr);
		obj->radius = obj->diameter / 2.0;
	}
	gen_new_image(s);
	ft_launch(s);
}

static t_vect	get_coeff(t_ray *r, t_cy *obj)
{
	t_vect	dist;
	t_vect	res;

	dist = substraction(r->origin, obj->center);
	res.x = scalaire(r->direction, r->direction) - pow(scalaire(r->direction,
				obj->direction), 2);
	res.y = 2 * (scalaire(r->direction, dist) - (scalaire(r->direction,
					obj->direction)) * (scalaire(dist, obj->direction)));
	res.z = scalaire(dist, dist) - pow(scalaire(dist, obj->direction), 2)
		- (obj->radius * obj->radius);
	return (res);
}

int	ft_intersec_cy(t_cy *obj, t_ray *r, t_vect *solution, double *t)
{
	double	discr;
	t_vect	coeff;

	coeff = get_coeff(r, obj);
	discr = (coeff.y * coeff.y) - (4 * coeff.x * coeff.z);
	if (discr < 0)
		return (EXIT_FAILURE);
	if (solution != NULL)
	{
		*t = get_root(coeff.x, coeff.y, discr);
		if (*t < EPSILON)
			return (EXIT_FAILURE);
		*solution = compute_intersec_pts(r, *t);
		if (compute_edge(obj, r, solution) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
