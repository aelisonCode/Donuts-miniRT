/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:37:14 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 11:26:45 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	select_state(t_scene *s, t_maps *ptr)
{
	t_maps	*tmp;

	if (!s || !ptr)
		return (EXIT_FAILURE);
	tmp = s->world;
	if (ptr->selected == TRUE)
		ptr->selected = FALSE;
	else if (ptr->selected == FALSE)
		ptr->selected = TRUE;
	while (tmp)
	{
		if (tmp != ptr)
			tmp->selected = FALSE;
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	select_next_obj(t_scene *s)
{
	t_maps	*tmp;

	if (!s)
		return (EXIT_FAILURE);
	tmp = s->world;
	while (tmp && tmp->selected != TRUE)
		tmp = tmp->next;
	if (!tmp)
		s->world->selected = TRUE;
	else
	{
		tmp->selected = FALSE;
		if (tmp->next)
			tmp->next->selected = TRUE;
		else
			s->world->selected = TRUE;
	}
	return (EXIT_SUCCESS);
}

char	*get_selected(t_scene *s)
{
	t_maps	*tmp;

	tmp = s->world;
	if (s->cam->selected == TRUE)
		return ("selected obj: CAMERA");
	if (s->light->selected == TRUE)
		return ("selected obj: LIGHT");
	while (tmp)
	{
		if (tmp->selected == TRUE)
		{
			if (tmp->type == Sphere)
				return ("selected Sphere");
			else if (tmp->type == Plane)
				return ("selected Plane");
			else if (tmp->type == Cylinder)
				return ("selected Cylender");
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	exec_obj_event(t_scene *s, int keycode)
{
	t_maps	*head;

	head = s->world;
	while (head)
	{
		if (head->selected == TRUE)
		{
			if (head->type == Sphere)
				ft_sp_event(s, head->struct_obj, keycode, 1.0);
			else if (head->type == Plane)
				ft_pl_event(s, head->struct_obj, keycode, 0.1);
			else if (head->type == Cylinder)
				ft_cy_event(s, head->struct_obj, keycode, 1.0);
		}
		head = head->next;
	}
}
