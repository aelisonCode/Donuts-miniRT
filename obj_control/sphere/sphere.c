/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:25 by aelison           #+#    #+#             */
/*   Updated: 2025/03/07 07:40:17 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_sp_event(t_scene *data, t_maps *curr, int keycode, double incr)
{
	t_sp	*tmp;

	if (!data || !curr)
		return ;
	tmp = curr->struct_obj;
	if (ft_get_event_state(data->event, diameter) == TRUE)
		ft_diameter(&tmp->diameter, &tmp->radius, keycode, incr);
	else if (ft_get_event_state(data->event, translation) == TRUE)
		ft_center(&tmp->center, keycode, incr);
	ft_exec_color(data, keycode, 5, &tmp->color);
	gen_new_image(data);
	ft_launch(data);
}

int	ft_intersec_sp(t_sp *obj, t_ray *r, double *t)
{
	double	a;
	double	b;
	double	c;
	t_vect	dist;
	double	discriminant;

	dist = substraction(r->origin, obj->center);
	a = scalaire(r->direction, r->direction);
	b = 2 * scalaire(r->direction, dist);
	c = scalaire(dist, dist) - pow(obj->radius, 2);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (EXIT_FAILURE);
	*t = get_root(a, b, discriminant);
	if (*t < EPSILON)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	exec_sp(t_scene *s, t_maps *curr, t_ray *r)
{
	double	t;

	if (!s || !curr || !r)
		return (EXIT_FAILURE);
	if (ft_intersec_sp(curr->struct_obj, r, &t) == EXIT_SUCCESS)
	{
		cmp_dist(s, curr, t);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
