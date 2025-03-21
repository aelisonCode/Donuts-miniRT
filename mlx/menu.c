/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:23:23 by aelison           #+#    #+#             */
/*   Updated: 2025/03/07 07:42:52 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	ft_obj_select(t_scene *s, t_vect msg_pos)
{
	t_color	obj_color;
	char	*msg;
	t_maps	*selected;

	selected = NULL;
	msg = get_selected(s, &selected);
	obj_color = get_col(selected);
	write_line(s->mlx, msg, msg_pos, obj_color.color);
	return (obj_color.color);
}

static void	show_mod(t_scene *s, t_vect msg_pos, int incr, int color)
{
	msg_pos.y += incr;
	if (ft_get_event_state(s->event, translation) == TRUE)
		write_line(s->mlx, "Translation selected", msg_pos, color);
	else if (ft_get_event_state(s->event, diameter) == TRUE)
		write_line(s->mlx, "Diameter selected", msg_pos, color);
	else if (ft_get_event_state(s->event, height) == TRUE)
		write_line(s->mlx, "Height selected", msg_pos, color);
	else if (ft_get_event_state(s->event, rotation) == TRUE)
		write_line(s->mlx, "Rotation selected", msg_pos, color);
	else if (ft_get_event_state(s->event, red) == TRUE)
		write_line(s->mlx, "Color Red selected", msg_pos, color);
	else if (ft_get_event_state(s->event, green) == TRUE)
		write_line(s->mlx, "Color Green selected", msg_pos, color);
	else if (ft_get_event_state(s->event, blue) == TRUE)
		write_line(s->mlx, "Color Blue selected", msg_pos, color);
	else if (ft_get_event_state(s->event, bright) == TRUE)
		write_line(s->mlx, "Intensity of light/ambient selected", msg_pos,
			color);
	else if (ft_get_event_state(s->event, fov) == TRUE)
		write_line(s->mlx, "Camera fov selected", msg_pos, color);
}

int	ft_show_control(t_scene *s)
{
	t_vect	msg_pos;
	int		incr;
	int		color;

	incr = 20;
	color = 0XFFFFFF;
	msg_pos = init_vect(5, 30, 0);
	if (s && s->show_ctrl == TRUE)
		ft_menu(s->mlx, msg_pos, incr, color);
	else if (s && s->show_status == TRUE)
	{
		if (s->light->selected == TRUE)
			write_line(s->mlx, "light selected", msg_pos, color);
		else if (s->cam->selected == TRUE)
			write_line(s->mlx, "Cam selected", msg_pos, color);
		else if (s->amlight->selected == TRUE)
			write_line(s->mlx, "Ambient light selected", msg_pos, color);
		else
			color = ft_obj_select(s, msg_pos);
		show_mod(s, msg_pos, incr, color);
	}
	return (EXIT_SUCCESS);
}
