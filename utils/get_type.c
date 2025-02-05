/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:01:43 by aelison           #+#    #+#             */
/*   Updated: 2025/01/22 13:05:40 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	*get_type(t_maps *obj, t_obj type)
{
	if (!obj)
		return (NULL);
	while (obj)
	{
		if (obj->type == type)
			return (obj->struct_obj);
		obj = obj->next;
	}
	return (NULL);
}

static void	retired_other(t_scene *scene, t_obj select)
{
	if (!scene)
		return ;
	if (select == Light)
		scene->cam->selected = FALSE;
	else if (select == Camera)
		scene->light->selected = FALSE;
}

static void	change_state(int *to_change)
{
	if (*to_change == FALSE)
		*to_change = TRUE;
	else if (*to_change == TRUE)
		*to_change = FALSE;
}

int	select_primary(t_scene *scene, int select)
{
	if (!scene)
		return (EXIT_FAILURE);
	if (select == LIGHT)
	{
		change_state(&scene->light->selected);
		retired_other(scene, Light);
	}
	else if (select == CAMERA)
	{
		change_state(&scene->cam->selected);
		retired_other(scene, Camera);
	}
	else if (select == ROTATE)
		change_state(&scene->do_rotation);
	return (EXIT_SUCCESS);
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
