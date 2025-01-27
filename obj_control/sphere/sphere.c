/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:25 by aelison           #+#    #+#             */
/*   Updated: 2025/01/23 09:22:47 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

 void	ft_sp_event(t_scene *data, int keycode)
 {
	t_sp	*obj;

	obj = get_type(data->world, Sphere);
 	if (!obj)
 		return ;
 	if (keycode == UP)
 		ft_translation(&obj->center, UP);
 	if (keycode == DOWN)
 		ft_translation(&obj->center, DOWN);
 	if (keycode == LEFT)
 		ft_translation(&obj->center, LEFT);
 	if (keycode == RIGHT)
 		ft_translation(&obj->center, RIGHT);
 	if (keycode == SCALE_UP)
 		ft_scale(&obj->diameter, SCALE_UP);
 	if (keycode == SCALE_DOWN)
 		ft_scale(&obj->diameter, SCALE_DOWN);
 	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->mlx_window);
 	send_ray(data, data->world);
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
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant < 0)
		return (EXIT_FAILURE);
	if (solution != NULL)
	{
		*solution = get_racine(a, b, discriminant);
		if (*solution < 0)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	exec_sp(t_scene *s, t_sp *obj, t_ray *r)
{
	int	res;

	res = 0X000000;
	if (ft_intersec_sp(obj, r, NULL) == EXIT_SUCCESS)
		res = add_ambient_col(obj->color.color, s->amlight->ratio);
	return (res);
}
