/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:04:52 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 15:22:06 by aelison          ###   ########.fr       */
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

static void	retired_other(int *a, int *b, int *c, int *d)
{
	*a = FALSE;
	*b = FALSE;
	*c = FALSE;
	*d = FALSE;
}

static void	select_aux(t_scene *s, int keycode)
{
	if (keycode == DIAMETER)
	{
		change_state(&s->do_diameter);
		retired_other(&s->do_z, &s->do_height, &s->do_color, &s->do_rotation);
	}
	else if (keycode == HEIGHT)
	{
		change_state(&s->do_height);
		retired_other(&s->do_z, &s->do_color, &s->do_diameter, &s->do_rotation);
	}
	else if (keycode == ROTATE)
	{
		change_state(&s->do_rotation);
		retired_other(&s->do_z, &s->do_color, &s->do_diameter, &s->do_height);
	}
	if (s->do_color == FALSE && s->do_z == FALSE && s->do_diameter == FALSE
		&& s->do_height == FALSE && s->do_rotation == FALSE)
		s->do_z = TRUE;
}

void	select_mod(t_scene *s, int keycode)
{
	if (keycode == RENDERER)
	{
		change_state(&s->do_pxl);
		return ;
	}
	if (keycode == RED || keycode == GREEN || keycode == BLUE)
	{
		if (s->do_color == keycode)
			s->do_color = FALSE;
		else
			s->do_color = keycode;
		retired_other(&s->do_z, &s->do_height, &s->do_diameter,
			&s->do_rotation);
	}
	else if (keycode == Z_AXIS)
	{
		change_state(&s->do_z);
		retired_other(&s->do_color, &s->do_height, &s->do_diameter,
			&s->do_rotation);
	}
	select_aux(s, keycode);
}
