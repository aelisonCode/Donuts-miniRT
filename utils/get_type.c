/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:01:43 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 14:06:08 by aelison          ###   ########.fr       */
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

void	change_state(int *to_change)
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
