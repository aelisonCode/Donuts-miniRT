/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:23:23 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 11:31:30 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static void	write_line(t_mlx *mlx, char *mssg, t_vect pos, int color)
{
	if (!mlx || !mssg)
		return ;
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color,
			mssg);
}

static void	ft_menu_unique(t_mlx *data, t_vect msg_pos, int incr, int color)
{
	write_line(data, "Tap 'C', 'L' to enter/out camera or light mode", msg_pos,
		color);
	msg_pos.y += incr;
	write_line(data, "Must quit these mode if you want to change !", msg_pos,
		color);
	msg_pos.y += incr;
	write_line(data, "Tap 'R' to enter rotation mode", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap 'Z' to enter Z Axis mode", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap 'D' to enter Diameter mode", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap 'H' to enter Height mode", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap '1' for red color", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap '2' for green color", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap '3' for blue color", msg_pos, color);
}

static void	ft_menu(t_mlx *data, t_vect msg_pos, int incr, int color)
{
	write_line(data, "Tap arrow to move on X and Y axis", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap TABULATION to change object", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap SHIFT to see object select", msg_pos, color);
	msg_pos.y += incr;
	write_line(data, "Tap + or - to change unique properties/ z axis:", msg_pos,
		color);
	msg_pos.y += incr;
	msg_pos.x += incr;
	ft_menu_unique(data, msg_pos, incr, color);
}

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
