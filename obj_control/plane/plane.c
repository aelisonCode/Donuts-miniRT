/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:25:45 by aelison           #+#    #+#             */
/*   Updated: 2025/03/07 07:40:23 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_pl_event(t_scene *data, t_maps *curr, int keycode, double incr)
{
	t_pl	*tmp;

	if (!data || !curr)
		return ;
	tmp = curr->struct_obj;
	if (ft_get_event_state(data->event, translation) == TRUE)
		ft_center(&tmp->point, keycode, incr + 1);
	else if (ft_get_event_state(data->event, rotation) == TRUE)
		ft_rotation(&tmp->direction, keycode, incr + 1);
	ft_exec_color(data, keycode, 5, &tmp->color);
	gen_new_image(data);
	ft_launch(data);
}

int	ft_intersec_pl(t_pl *obj, t_ray *ray, double *t)
{
	double	denominator;
	t_vect	x;

	denominator = scalaire(ray->direction, obj->direction);
	if (fabs(denominator) < EPSILON)
		return (EXIT_FAILURE);
	x = substraction(obj->point, ray->origin);
	*t = scalaire(x, obj->direction) / denominator;
	if (*t > EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	exec_pl(t_scene *s, t_maps *obj, t_ray *r)
{
	double	t;

	if (ft_intersec_pl(obj->struct_obj, r, &t) == EXIT_SUCCESS)
	{
		cmp_dist(s, obj, t);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
