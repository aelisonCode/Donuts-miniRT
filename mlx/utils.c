/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:04:52 by aelison           #+#    #+#             */
/*   Updated: 2025/02/25 14:04:18 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*tmp;

	if (x >= 0 && x <= WINDOW_X)
	{
		if (y >= 0 && y <= WINDOW_Y)
		{
			tmp = data->img_addr + (y * data->size_line + x
					* (data->byte_p_pixel / 8));
			*(unsigned int *)tmp = color;
		}
	}
}

void	gen_new_image(t_scene *scene)
{
	t_mlx	*data;

	data = scene->mlx;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_X, WINDOW_Y);
	if (data->img_ptr == NULL)
		ft_close_window(scene);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->byte_p_pixel,
			&data->size_line, &data->endian);
	if (data->img_addr == NULL)
		ft_close_window(scene);
}

static void	select_aux(t_scene *s, int keycode)
{
	if (keycode == DIAMETER)
		ft_select_event(s->event, diameter, TRUE);
	else if (keycode == HEIGHT)
		ft_select_event(s->event, height, TRUE);
	else if (keycode == ROTATE)
		ft_select_event(s->event, rotation, TRUE);
	else if (keycode == FOV)
		ft_select_event(s->event, fov, TRUE);
	else if (keycode == BRIGHT)
		ft_select_event(s->event, bright, TRUE);
}

void	select_mod(t_scene *s, int keycode)
{
	if (keycode == RENDERER)
	{
		change_state(&s->pixelize);
		return ;
	}
	else if (keycode == RED)
		ft_select_event(s->event, red, TRUE);
	else if (keycode == GREEN)
		ft_select_event(s->event, green, TRUE);
	else if (keycode == BLUE)
		ft_select_event(s->event, blue, TRUE);
	else if (keycode == Z_AXIS)
		ft_select_event(s->event, translation, TRUE);
	select_aux(s, keycode);
	ft_protect_event(s->event);
}
