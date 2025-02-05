/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:21:54 by aelison           #+#    #+#             */
/*   Updated: 2025/02/04 08:32:02 by aelison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	change_state(t_scene *s, t_maps *ptr)
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

static t_color	*get_col(t_maps *obj)
{
	t_sp	*tmp_sp;
	t_pl	*tmp_pl;
	t_cy	*tmp_cy;

	tmp_sp = NULL;
	tmp_pl = NULL;
	tmp_cy = NULL;
	if (!obj)
		return (NULL);
	if (obj->type == Sphere)
	{
		tmp_sp = obj->struct_obj;
		return (&tmp_sp->color);
	}
	if (obj->type == Plane)
	{
		tmp_pl = obj->struct_obj;
		return (&tmp_pl->color);
	}
	if (obj->type == Cylinder)
	{
		tmp_cy = obj->struct_obj;
		return (&tmp_cy->color);
	}
	return (NULL);
}

static int	rand_col(t_color *col)
{
	if (!col)
		return (EXIT_FAILURE);
	if (col->r < 255)
		col->r += 50;
	else
		col->r = 0;
	if (col->g < 255)
		col->g += 50;
	else
		col->g = 0;
	if (col->b < 255)
		col->b += 50;
	else
		col->b = 0;
	col->color = create_color(col->r, col->g, col->b);
	return (EXIT_SUCCESS);
}

static int	get_obj(t_scene *s, int x, int y, int do_move)
{
	t_ray	r;
	t_vect	solution;
	double	t;
	t_maps	*head;

	r = create_ray(&s->cam->view_point, s->p, x, y);
	head = s->world;
	while (head)
	{
		if (head->type == Sphere)
		{
			if (ft_intersec_sp(head->struct_obj, &r, &solution, &t) == EXIT_SUCCESS)
			{
				if (do_move == 0)
					return (change_state(s, head));
				else
					return (rand_col(get_col(head)));
			}
		}
		else if (head->type == Plane)
		{
			if (ft_intersec_pl(head->struct_obj, &r, &solution, &t) == EXIT_SUCCESS)
			{
				if (do_move == 0)
					return (change_state(s, head));
				else
					return (rand_col(get_col(head)));
			}
		}
		else if (head->type == Cylinder)
		{
			if (ft_intersec_cy(head->struct_obj, &r, &solution, &t) == EXIT_SUCCESS)
			{
				if (do_move == 0)
					return (change_state(s, head));
				else
					return (rand_col(get_col(head)));
			}
		}

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
			return (select_next_obj(data));
		if (keycode == LIGHT || keycode == CAMERA || keycode == ROTATE)
			return (select_primary(data, keycode));
		type = is_primary_selected(data);
		if (type != Non_object)
			control_primary(data, type, keycode);
		else
			exec_obj_event(data, keycode);
	}
	return (result);
}
