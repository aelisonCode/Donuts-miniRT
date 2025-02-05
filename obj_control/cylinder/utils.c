/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:09:10 by aelison          #+#    #+#             */
/*   Updated: 2025/02/04 09:24:08 by aelison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_cy_event(t_scene *s, t_cy *obj, int keycode, double incr)
{
	if (s->do_rotation == FALSE)
	{
		if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
			ft_translation(&obj->center, keycode, incr);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_translation(&obj->center, keycode, -incr);
	}
	else if (s->do_rotation == TRUE)
	{
		if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
			ft_rotate(&obj->direction, keycode, 3);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_rotate(&obj->direction, keycode, 3);
	}
	if (keycode == SCALE_UP || keycode == SCALE_DOWN)
	{
		ft_scale(&obj->diameter, keycode, incr);
		obj->radius = obj->diameter / 2.0;
	}
	gen_new_image(s);
	ft_launch(s);
}

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
		*t = get_root(a, b, discr);
		if (*t < 0)
			return (EXIT_FAILURE);
		*solution = compute_intersec_pts(r, *t);
		if (ft_cy_limit(obj, solution) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


