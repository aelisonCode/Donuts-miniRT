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
	char	*tmp;

	tmp = "no selected object";
	if (!mlx)
		return ;
	if (!mssg)
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, tmp);
	else
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color,
			mssg);
}

static void	ft_menu(t_mlx *data, t_vect msg_pos, int incr)
{
	write_line(data, "Tap arrow to move on X and Y axis", msg_pos, 0X00FF00);
	msg_pos.y += incr;
	write_line(data, "Tap 8 or 2 to move on Z axis", msg_pos, 0X00FF00);
	msg_pos.y += incr;
	write_line(data, "Tap 'C', 'L' to enter/out camera or light mode", msg_pos,
		0X00FF00);
	msg_pos.y += incr;
	write_line(data, "Tap 'R' to enter/out rotation mode", msg_pos, 0X00FF00);
}

int	ft_show_control(t_scene *s)
{
	t_vect	msg_pos;
	int		incr;

	incr = 20;
	msg_pos = init_vect(5, 30, 0);
	if (s && s->show_control == TRUE)
		ft_menu(s->mlx, msg_pos, incr);
	else if (s && s->current == TRUE)
		write_line(s->mlx, get_selected(s), msg_pos, 0XAF0FFF);
	return (EXIT_SUCCESS);
}
