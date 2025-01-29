/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:33:31 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 10:58:41 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"
#include <math.h>

double	dist_euclidienne(t_vect point, t_vect target)
{
	double	res;

	res = sqrt(pow(point.x - target.x, 2) + pow(point.y - target.y, 2)
			+ pow(point.z - target.z, 2));
	return (fabs(res));
}

double	val_sphere(t_sp *sphere, t_vect ref)
{
	double	res;

	res = dist_euclidienne(sphere->center, ref);
	return (res);
}

double	val_plane(t_pl *plane, t_vect ref)
{
	double	res;

	res = dist_euclidienne(plane->point, ref);
	return (res);
}

void	select_obj(t_scene *scene, int x, int y)
{
	t_maps	*tmp;
	t_vect	ref;
	double	val;
	t_obj	ptr;
	double	min;

	if (!scene)
		return ;
	ptr = Non_object;
	min = (double)-1;
	tmp = scene->world;
	ref = init_vect(x, y, 0);
	while (tmp)
	{
		if (tmp->type == Sphere)
			val = val_sphere(tmp->struct_obj, ref);
		else if (tmp->type == Plane)
			val = val_plane(tmp->struct_obj, ref);
		if (val < min)
		{
			ptr = tmp->type;
			min = val;
		}
		tmp = tmp->next;
	}
}

void	ft_launch(t_scene *scene)
{
	t_mlx	*data;
	t_maps	*tmp;

	if (!scene)
		return ;
	data = scene->mlx;
	tmp = scene->world;
	while (tmp)
	{
		loop_screen(scene, tmp);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0,
		0);
	mlx_key_hook(data->mlx_window, ft_exec_input, scene);
	mlx_mouse_hook(data->mlx_window, on_button_pressed, scene);
	mlx_hook(data->mlx_window, 17, 1L << 17, ft_close_window, scene);
	mlx_loop(data->mlx_ptr);
}
