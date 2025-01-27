/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:21:54 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 10:12:35 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	on_button_pressed(int button, int x, int y, void *param)
{
	t_scene	*s;
	t_sp	*obj;
	t_ray	r;

	s = (t_scene *)param;
	obj = get_type(s->world, Sphere);
	if (obj != NULL)
	{
		if (button == LEFT_BUTTON)
		{
			r = create_ray(s->cam, s->p, x, y);
			if (ft_intersec_sp(obj, &r, NULL) == EXIT_SUCCESS)
				ft_put_pixel(s->mlx, x, y, 0XFF000000);
		}
		ft_launch(s);
	}
	return (EXIT_FAILURE);
}

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
	send_ray(data->mlx, data->p, data->cam, obj);
	ft_launch(data);
}

/*	Si appuie sur echappe quitte le programme	*/
int	ft_exec_input(int keycode, t_scene *data)
{
	int	result;

	result = EXIT_FAILURE;
	if (data)
	{
		if (keycode == K_ESCAPE)
			result = ft_close_window(data);
		ft_sp_event(data, keycode);
	}
	return (result);
}
