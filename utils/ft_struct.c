/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:43:45 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/28 14:07:15 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static void	retired_other(t_scene *scene, t_obj select)
{
	if (!scene)
		return ;
	if (select == Light)
		scene->cam->selected = FALSE;
	else if (select == Camera)
		scene->light->selected = FALSE;
}

void	select_primary(t_scene *scene, t_obj select)
{
	if (!scene)
		return ;
	if (select == Light)
	{
		if (scene->light->selected == FALSE)
			scene->light->selected = TRUE;
		else
			scene->light->selected = FALSE;
		retired_other(scene, Light);
	}
	else if (select == Camera)
	{
		if (scene->light->selected == FALSE)
			scene->light->selected = TRUE;
		else
			scene->light->selected = FALSE;
		retired_other(scene, Camera);
	}
}

t_obj	is_primary_selected(t_scene *scene)
{
	if (!scene)
		return (Non_object);
	if (scene->cam->selected == TRUE)
		return (Camera);
	else if (scene->light->selected == TRUE)
		return (Light);
	return (Non_object);
}

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
}
