/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:39:16 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 15:59:13 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_translation(t_vect *point, int move, double incr)
{
	if (!point)
		return ;
	if (move == UP)
		point->y += incr;
	else if (move == DOWN)
		point->y -= incr;
	else if (move == LEFT)
		point->x -= incr;
	else if (move == RIGHT)
		point->x += incr;
	else if (move == Z_UP)
		point->z += incr;
	else if (move == Z_DOWN)
		point->z -= incr;
}

void	ft_rotate_on_z(t_vect *direction, double ratio_deg)
{
	double	ratio_rad;
	t_vect	v;

	v = ft_normalize(*direction);
	ratio_rad = ratio_deg * (M_PI / 180);
	direction->x = v.x * cos(ratio_rad) - v.y * sin(ratio_rad);
	direction->y = v.x * sin(ratio_rad) + v.y * cos(ratio_rad);
	direction->z = v.z;
}

void	ft_rotate_on_y(t_vect *direction, double ratio_deg)
{
	double	ratio_rad;
	t_vect	v;

	v = ft_normalize(*direction);
	ratio_rad = ratio_deg * (M_PI / 180);
	direction->y = v.y;
	direction->x = v.x * cos(ratio_rad) + v.z * sin(ratio_rad);
	direction->z = (-1 * v.x) * sin(ratio_rad) + v.z * cos(ratio_rad);
}

void	ft_rotate_on_x(t_vect *direction, double ratio_deg)
{
	double	ratio_rad;
	t_vect	v;

	v = ft_normalize(*direction);
	ratio_rad = ratio_deg * (M_PI / 180);
	direction->x = v.x;
	direction->y = v.y * cos(ratio_rad) - v.z * sin(ratio_rad);
	direction->z = v.y * sin(ratio_rad) + v.z * cos(ratio_rad);

}

void	ft_rotate(t_vect *direction,int keycode, int incr_deg)
{
	if (!direction)
		return ;
	if (keycode == Z_UP)
		ft_rotate_on_z(direction, incr_deg);
	else if (keycode == Z_DOWN)
		ft_rotate_on_z(direction, -incr_deg);
	else if (keycode == UP)
		ft_rotate_on_y(direction, incr_deg);
	else if (keycode == DOWN)
		ft_rotate_on_y(direction, -incr_deg);
	else if (keycode == LEFT)
		ft_rotate_on_x(direction, incr_deg);
	else if (keycode == RIGHT)
		ft_rotate_on_x(direction, -incr_deg);
}


void	ft_scale(double *value, int move, double incr)
{
	if (!value)
		return ;
	if (move == SCALE_UP)
		*value += incr;
	else if (move == SCALE_DOWN)
		*value -= incr;
}
