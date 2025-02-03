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

int	select_primary(t_scene *scene, t_obj select)
{
	if (!scene)
		return (EXIT_FAILURE);
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
		if (scene->cam->selected == FALSE)
			scene->cam->selected = TRUE;
		else
			scene->cam->selected = FALSE;
		retired_other(scene, Camera);
	}
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
