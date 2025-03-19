/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:43:45 by mravelon          #+#    #+#             */
/*   Updated: 2025/03/07 13:00:43 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	control_light(t_scene *s, t_l *light, int keycode, double incr)
{
	int	result;

	result = TRUE;
	if (!light || !s)
		return (FALSE);
	ft_exec_color(s, keycode, 5, &light->color);
	if (ft_get_event_state(s->event, translation) == TRUE)
		ft_center(&light->pos, keycode, incr);
	else if (ft_get_event_state(s->event, bright) == TRUE)
	{
		if (keycode == SCALE_DOWN && light->bright > 0)
		{
			ft_scale(&light->bright, keycode, 0.1);
			if (light->bright < 0.0)
				light->bright = 0;
		}
		else if (keycode == SCALE_UP && light->bright < 1.0)
		{
			ft_scale(&light->bright, keycode, 0.1);
			if (light->bright > 1.0)
				light->bright = 1.0;
		}
	}
	return (result);
}

int	control_cam(t_scene *s, t_c *cam, int keycode, double incr)
{
	int	result;

	result = TRUE;
	if (!cam || !s)
		return (FALSE);
	if (ft_get_event_state(s->event, rotation) == TRUE)
		ft_rotation(&cam->direction, keycode, -incr * 5);
	else if (ft_get_event_state(s->event, translation) == TRUE)
		ft_center(&cam->view_point, keycode, incr);
	else if (ft_get_event_state(s->event, fov) == TRUE)
	{
		if (cam->fov > 0 && keycode == SCALE_DOWN)
			ft_scale(&cam->fov, keycode, incr * 5);
		if (cam->fov < 180 && keycode == SCALE_UP)
			ft_scale(&cam->fov, keycode, incr * 5);
		if (cam->fov < 0)
			cam->fov = 0;
		else if (cam->fov > 180)
			cam->fov = 180;
	}
	free(s->p);
	s->p = init_pjct(cam, 1);
	return (result);
}

int	control_ambient(t_scene *s, t_a *am, int keycode, double incr)
{
	int	result;

	result = TRUE;
	if (!am || !s)
		return (FALSE);
	ft_exec_color(s, keycode, 5, &am->color);
	if (ft_get_event_state(s->event, bright) == TRUE)
	{
		if (keycode == SCALE_DOWN && am->ratio > 0)
		{
			ft_scale(&am->ratio, keycode, incr);
			if (am->ratio < 0.0)
				am->ratio = 0;
		}
		else if (keycode == SCALE_UP && am->ratio < 1.0)
		{
			ft_scale(&am->ratio, keycode, incr);
			if (am->ratio > 1.0)
				am->ratio = 1.0;
		}
	}
	return (result);
}

void	control_primary(t_scene *scene, t_obj type, int keycode)
{
	if (keycode != LIGHT && type == Light)
	{
		if (control_light(scene, scene->light, keycode, 2.0) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
	if (keycode != CAMERA && type == Camera)
	{
		if (control_cam(scene, scene->cam, keycode, 0.5) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
	if (keycode != AMBIENT && type == Ambient_l)
	{
		if (control_ambient(scene, scene->amlight, keycode, 0.1) == FALSE)
			return ;
		gen_new_image(scene);
		ft_launch(scene);
	}
}
