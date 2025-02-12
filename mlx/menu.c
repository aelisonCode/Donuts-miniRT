/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:23:23 by aelison           #+#    #+#             */
/*   Updated: 2025/02/12 09:58:59 by aelison          ###   ########.fr       */
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
	if (s->do_color != FALSE)
		write_line(s->mlx, "color selected", msg_pos, color);
	else if (s->do_z == TRUE)
		write_line(s->mlx, "Z axis selected", msg_pos, color);
	else if (s->do_diameter == TRUE)
		write_line(s->mlx, "Diameter selected", msg_pos, color);
	else if (s->do_height == TRUE)
		write_line(s->mlx, "Height selected", msg_pos, color);
	else if (s->do_rotation == TRUE)
		write_line(s->mlx, "Rotation selected", msg_pos, color);
}

int	ft_show_control(t_scene *s)
{
	t_vect	msg_pos;
	int		incr;
	int		color;

	incr = 20;
	color = 0X655AFF;
	msg_pos = init_vect(5, 30, 0);
	if (s && s->show_control == TRUE)
		ft_menu(s->mlx, msg_pos, incr, color);
	else if (s && s->current == TRUE)
	{
		if (s->light->selected == TRUE)
			write_line(s->mlx, "light selected", msg_pos, color);
		else if (s->cam->selected == TRUE)
			write_line(s->mlx, "Cam selected", msg_pos, color);
		else
			color = ft_obj_select(s, msg_pos);
		show_mod(s, msg_pos, incr, color);
	}
	return (EXIT_SUCCESS);
}
