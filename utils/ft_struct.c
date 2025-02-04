/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:43:45 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/04 08:30:09 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	control_light(t_l *light, int keycode, double incr)
{
	int		result;

	result = TRUE;
	if (!light)
		return (FALSE);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
		ft_translation(&light->pos, keycode, incr);
	else if (keycode == Z_UP || keycode == Z_DOWN)
		ft_translation(&light->pos, keycode, -incr);
	else if (keycode == SCALE_UP && light->bright < 1.0)
		ft_scale(&light->bright, keycode, 0.1);
	else if (keycode == SCALE_DOWN && light->bright > 0.0)
		ft_scale(&light->bright, keycode, 0.1);
	else
		result = FALSE;
	return (result);
}

int	control_cam(int do_rotation, t_c *cam, int keycode, double incr)
{
	int		result;

	result = TRUE;
	if (!cam)
		return (FALSE);
	if (do_rotation == FALSE)
	{
		if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
			ft_translation(&cam->view_point, keycode, incr);
		else if (keycode == Z_UP || keycode == Z_DOWN)
			ft_translation(&cam->view_point, keycode, incr);
	}
	else if (do_rotation == TRUE)
	{
		if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
			ft_rotate(&cam->direction, keycode, 20);
		else if (keycode == Z_UP || keycode == Z_DOWN)
			ft_rotate(&cam->direction, keycode, 20);
	}
	else
		result = FALSE;
	return (result);
}

void	control_primary(t_scene *scene, t_obj type, int keycode)
{
	if (!scene)
		return ;
	if (keycode != LIGHT && type == Light)
	{
		if (control_light(scene->light, keycode, 2.0) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
	else if (keycode != CAMERA && type == Camera)
	{
		if (control_cam(scene->do_rotation, scene->cam, keycode, -0.1) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
}
