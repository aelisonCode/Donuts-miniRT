/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:43:45 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/30 13:31:47 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	control_light(t_l *light, int keycode)
{
	int		result;
	double	incr;

	incr = 3.0;
	result = TRUE;
	if (!light)
		return (FALSE);
	if (keycode == LEFT)
		ft_translation(&light->pos, LEFT, incr);
	else if (keycode == RIGHT)
		ft_translation(&light->pos, RIGHT, incr);
	else if (keycode == UP)
		ft_translation(&light->pos, UP, incr);
	else if (keycode == DOWN)
		ft_translation(&light->pos, DOWN, incr);
	else if (keycode == Z_UP)
		ft_translation(&light->pos, Z_UP, -incr);
	else if (keycode == Z_DOWN)
		ft_translation(&light->pos, Z_DOWN, -incr);
	else if (keycode == SCALE_UP && light->bright < 1.0)
		ft_scale(&light->bright, keycode, 0.1);
	else if (keycode == SCALE_DOWN && light->bright > 0.0)
		ft_scale(&light->bright, keycode, 0.1);
	else
		result = FALSE;
	return (result);
}

int	control_cam(t_c *cam, int keycode)
{
	int		result;
	double	incr;

	incr = -0.1;
	result = TRUE;
	if (!cam)
		return (FALSE);
	if (keycode == LEFT)
		ft_translation(&cam->view_point, LEFT, incr);
	else if (keycode == RIGHT)
		ft_translation(&cam->view_point, RIGHT, incr);
	else if (keycode == UP)
		ft_translation(&cam->view_point, UP, incr);
	else if (keycode == DOWN)
		ft_translation(&cam->view_point, DOWN, incr);
	else if (keycode == Z_UP)
		ft_translation(&cam->view_point, Z_UP, incr);
	else if (keycode == Z_DOWN)
		ft_translation(&cam->view_point, Z_DOWN, incr);
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
		if (control_light(scene->light, keycode) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
	else if (keycode != CAMERA && type == Camera)
	{
		if (control_cam(scene->cam, keycode) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
}
