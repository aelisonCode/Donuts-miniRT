/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:57:58 by aelison           #+#    #+#             */
/*   Updated: 2025/02/12 10:00:03 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	write_line(t_mlx *mlx, char *mssg, t_vect pos, int color)
{
	if (!mlx || !mssg)
		return ;
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, mssg);
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

void	ft_menu(t_mlx *data, t_vect msg_pos, int incr, int color)
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
