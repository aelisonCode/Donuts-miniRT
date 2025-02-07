/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:09:10 by aelison          #+#    #+#             */
/*   Updated: 2025/02/06 15:51:40 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_cy_event(t_scene *data, t_maps *curr, int keycode, double incr)
{
	t_cy	*tmp;

	if (!data || !curr)
		return ;
	tmp = curr->struct_obj;
	if (data->do_color != FALSE && (keycode == SCALE_UP
			|| keycode == SCALE_DOWN))
		ft_color(&tmp->color, data->do_color, keycode, 5);
	else if (data->do_diameter == TRUE)
		ft_diameter(&tmp->diameter, &tmp->radius, keycode, incr);
	else if (data->do_height == TRUE)
		ft_height(&tmp->height, keycode, incr);
	else if (data->do_z == TRUE)
		ft_center(&tmp->center, keycode, incr);
	else if (data->do_rotation == TRUE)
		ft_rotation(&tmp->direction, keycode, 10);
	gen_new_image(data);
	ft_launch(data);
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
		*t = get_root(coeff.x, coeff.y, discr, &obj->t2);
		if (*t < EPSILON)
			return (EXIT_FAILURE);
		*solution = compute_intersec_pts(r, *t);
		if (compute_edge(obj, r, solution) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
