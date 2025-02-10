/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:43:45 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/04 08:30:09 by aelison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	control_light(t_scene *s, t_l *light, int keycode, double incr)
{
	int	result;

	result = TRUE;
	if (!light || !s)
		return (FALSE);
	if (s->do_z == TRUE)
		ft_center(&light->pos, keycode, incr);
	if (s->do_color != FALSE)
		ft_color(&light->color, s->do_color, keycode, incr);
	if (s->do_z == FALSE)
	{
		if (keycode == SCALE_DOWN && light->bright > 0)
			ft_scale(&light->bright, keycode, 0.1);
		else if (keycode == SCALE_UP && light->bright < 1.0)
			ft_scale(&light->bright, keycode, 0.1);
	}
	return (result);
}

int	control_cam(t_scene *s, t_c *cam, int keycode, double incr)
{
	int	result;

	result = TRUE;
	if (!cam || !s)
		return (FALSE);
	if (s->do_rotation == TRUE)
	{
		ft_rotation(&cam->direction, keycode, incr);
		free(s->p);
		s->p = init_pjct(cam, 1);
	}
	if (s->do_z == TRUE)
		ft_center(&cam->view_point, keycode, incr);
	if (s->do_z == FALSE)
	{
		if (cam->fov > 0 && keycode == SCALE_DOWN)
			ft_scale(&cam->fov, keycode, incr * 5);
		if (cam->fov < 180 && keycode == SCALE_UP)
			ft_scale(&cam->fov, keycode, incr * 5);
		free(s->p);
		s->p = init_pjct(cam, 1);
	}
	return (result);
}

void	control_primary(t_scene *scene, t_obj type, int keycode)
{
	if (!scene)
		return ;
	if (keycode != LIGHT && type == Light)
	{
		if (control_light(scene, scene->light, keycode, 2.0) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
	if (keycode != CAMERA && type == Camera)
	{
		if (control_cam(scene, scene->cam, keycode, -0.1) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
}
