/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:21:54 by aelison           #+#    #+#             */
/*   Updated: 2025/03/06 10:37:51 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static void	obj_aux(int tmp, int *res, t_maps **near, t_maps *head)
{
	if (tmp != -1)
	{
		if (*res == -1)
		{
			*res = tmp;
			*near = head;
		}
		else
		{
			if (*res > tmp)
			{
				*res = tmp;
				*near = head;
			}
		}
	}
}

static int	get_obj(t_scene *s, int x, int y)
{
	int		tmp;
	int		res;
	t_ray	r;
	t_maps	*head;
	t_maps	*near;

	r = create_ray(&s->cam->view_point, s->p, x, y);
	head = s->world;
	res = -1;
	near = NULL;
	while (head)
	{
		tmp = ft_mouse_to_obj(head, &r);
		obj_aux(tmp, &res, &near, head);
		head = head->next;
	}
	if (near != NULL)
		select_state(s, near);
	return (EXIT_SUCCESS);
}

int	on_button_pressed(int button, int x, int y, void *param)
{
	t_scene	*s;

	if (!param)
		return (EXIT_FAILURE);
	s = (t_scene *)param;
	if (button == LEFT_BUTTON)
		return (get_obj(s, x, y));
	return (EXIT_SUCCESS);
}

int	ft_pressed(int keycode, t_scene *s)
{
	if (s)
	{
		if (keycode == CTRL)
			s->show_ctrl = TRUE;
		if (keycode == SHIFT)
			s->show_status = TRUE;
	}
	return (EXIT_SUCCESS);
}

int	ft_released(int keycode, t_scene *s)
{
	t_obj	type;

	if (s)
	{
		if (keycode == CTRL)
			s->show_ctrl = FALSE;
		if (keycode == SHIFT)
			s->show_status = FALSE;
		select_mod(s, keycode);
		if (keycode == K_ESCAPE)
			ft_close_window(s);
		if (keycode == CHANGE_OBJ)
			return (select_next_obj(s));
		if (keycode == LIGHT || keycode == CAMERA || keycode == AMBIENT)
			return (select_primary(s, keycode));
		type = is_primary_selected(s);
		if (type != Non_object)
			control_primary(s, type, keycode);
		else
			exec_obj_event(s, keycode);
	}
	return (EXIT_SUCCESS);
}
