/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:33:31 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 11:24:33 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_config_event(t_scene *scene)
{
	t_mlx	*data;

	if (!scene)
		return ;
	data = scene->mlx;
	mlx_hook(data->mlx_window, 2, 1L << 0, ft_pressed, scene);
	mlx_hook(data->mlx_window, 3, 1L << 1, ft_released, scene);
	mlx_hook(data->mlx_window, 17, 1L << 17, ft_close_window, scene);
	mlx_mouse_hook(data->mlx_window, on_button_pressed, scene);
	mlx_loop_hook(data->mlx_ptr, ft_show_control, scene);
}

void	ft_launch(t_scene *scene)
{
	t_mlx	*data;

	if (!scene)
		return ;
	data = scene->mlx;
	loop_screen(scene);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0,
		0);
	ft_config_event(scene);
	mlx_loop(data->mlx_ptr);
}
