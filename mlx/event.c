/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:21:54 by aelison           #+#    #+#             */
/*   Updated: 2025/01/30 15:22:59 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	on_button_pressed(int button, int x, int y, void *param)
{
	t_scene	*s;
	t_sp	*obj;

	s = (t_scene *)param;
	obj = get_type(s->world, Sphere);
	if (obj != NULL)
	{
		if (button == LEFT_BUTTON)
		{
			ft_put_pixel(s->mlx, x, y, 0XFF00FF);
		}
		mlx_put_image_to_window(s->mlx->mlx_ptr, s->mlx->mlx_window,
			s->mlx->img_ptr, 0, 0);
	}
	return (EXIT_FAILURE);
}

void	select_next_obj(t_scene *s)
{
	t_maps	*tmp;

	if (!s)
		return ;
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
				ft_sp_event(s, head->struct_obj, keycode);
			else if (head->type == Plane)
				ft_pl_event(s, head->struct_obj, keycode);
		}
		head = head->next;
	}
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
		if (keycode == CHANGE_OBJ)
		{
			select_next_obj(data);
			return (EXIT_SUCCESS);
		}
		if (keycode == LIGHT)
		{
			select_primary(data, Light);
			return (EXIT_SUCCESS);
		}
		else if (keycode == CAMERA)
		{
			select_primary(data, Camera);
			return (EXIT_SUCCESS);
		}
		type = is_primary_selected(data);
		// ft_menu(data);
		if (type != Non_object)
			control_primary(data, type, keycode);
		else
			exec_obj_event(data, keycode);
	}
	return (result);
}
