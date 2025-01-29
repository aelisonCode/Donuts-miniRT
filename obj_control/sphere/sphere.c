/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:25 by aelison           #+#    #+#             */
/*   Updated: 2025/01/28 14:14:14 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_sp_event(t_scene *data, int keycode)
{
	t_sp	*obj;
	double	incr;

	incr = 1.0;
	obj = get_type(data->world, Sphere);
	if (!obj)
		return ;
	if (keycode == UP)
		ft_translation(&obj->center, UP, incr);
	if (keycode == DOWN)
		ft_translation(&obj->center, DOWN, incr);
	if (keycode == LEFT)
		ft_translation(&obj->center, LEFT, incr);
	if (keycode == RIGHT)
		ft_translation(&obj->center, RIGHT, incr);
	if (keycode == SCALE_UP)
		ft_scale(&obj->diameter, SCALE_UP, incr);
	if (keycode == SCALE_DOWN)
		ft_scale(&obj->diameter, SCALE_DOWN, incr);
	obj->radius = obj->diameter / 2;
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->mlx_window);
	ft_launch(data);
}

int	ft_intersec_sp(t_sp *obj, t_ray *r, double *solution)
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
	if (solution != NULL)
	{
		*solution = get_racine(a, b, discriminant);
		if (*solution < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	exec_sp(t_scene *s, t_sp *obj, t_ray *r)
{
	int		res;
	double	solution;
	double	lambert;
	t_vect	point;

	res = 0X000000;
	if (ft_intersec_sp(obj, r, &solution) == EXIT_SUCCESS)
	{
		point = sum(r->origin, vect_dot_val(r->direction, solution));
		lambert = lambertienne_reflection(COEFF_REFCT, s->light, &obj->center,
				point);
		res = gen_color(obj->color.color, s->amlight, lambert, REFRACTION_AM);
	}
	return (res);
}
