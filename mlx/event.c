/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:21:54 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 11:22:00 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	get_obj(t_scene *s, int x, int y, int do_move)
{
	int		status;
	t_ray	r;
	t_maps	*head;

	r = create_ray(&s->cam->view_point, s->p, x, y);
	head = s->world;
	while (head)
	{
		status = ft_mouse_to_obj(s, head, &r, do_move);
		if (status == EXIT_SUCCESS)
			return (status);
		head = head->next;
	}
	return (EXIT_SUCCESS);
}

int	on_button_pressed(int button, int x, int y, void *param)
{
	t_scene	*s;

	if (!param)
		return (EXIT_FAILURE);
	s = (t_scene *)param;
	if (button == LEFT_BUTTON)
		return (get_obj(s, x, y, 0));
	else if (button == RIGHT_BUTTON)
	{
		get_obj(s, x, y, 1);
		gen_new_image(s);
		ft_launch(s);
	}
	return (EXIT_SUCCESS);
}

int	ft_pressed(int keycode, t_scene *s)
{
	if (s)
	{
		if (keycode == CTRL)
			s->show_control = TRUE;
		if (keycode == SHIFT)
			s->current = TRUE;
	}
	return (EXIT_SUCCESS);
}

int	ft_released(int keycode, t_scene *s)
{
	t_obj	type;

	if (s)
	{
		if (keycode == CTRL)
			s->show_control = FALSE;
		if (keycode == SHIFT)
			s->current = FALSE;
		if (keycode == K_ESCAPE)
			ft_close_window(s);
		if (keycode == CHANGE_OBJ)
			return (select_next_obj(s));
		if (keycode == LIGHT || keycode == CAMERA || keycode == ROTATE)
			return (select_primary(s, keycode));
		type = is_primary_selected(s);
		if (type != Non_object)
			control_primary(s, type, keycode);
		else
			exec_obj_event(s, keycode);
	}
	return (EXIT_SUCCESS);
}
