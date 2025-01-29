/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:21:54 by aelison           #+#    #+#             */
/*   Updated: 2025/01/28 13:56:53 by aelison          ###   ########.fr       */
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
			r = create_ray(&s->cam->view_point, s->p, x, y);
			if (ft_intersec_sp(obj, &r, NULL) == EXIT_SUCCESS)
				ft_put_pixel(s->mlx, x, y, 0XFF000000);
		}
		ft_launch(s);
	}
	return (EXIT_FAILURE);
}

int	ft_exec_input(int keycode, t_scene *data)
{
	int		result;
	t_obj	type;

	result = EXIT_FAILURE;
	if (data)
	{
		if (keycode == K_ESCAPE)
			result = ft_close_window(data);
		if (keycode == LIGHT)
			select_primary(data, Light);
		else if (keycode == CAMERA)
			select_primary(data, Camera);
		type = is_primary_selected(data);
		if (type != Non_object)
			control_primary(data, type, keycode);
		else
			ft_sp_event(data, keycode);
	}
	return (result);
}
