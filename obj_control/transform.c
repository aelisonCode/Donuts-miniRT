/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:13:53 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 15:18:40 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_center(t_vect *to_change, int keycode, double incr)
{
	if (!to_change)
		return ;
	if (keycode == LEFT || keycode == RIGHT || keycode == UP
		|| keycode == DOWN)
		ft_translation(to_change, keycode, incr);
	if (keycode == SCALE_UP || keycode == SCALE_DOWN)
		ft_translation(to_change, keycode, -incr);
}

void	ft_rotation(t_vect *to_change, int keycode, double incr)
{
	if (!to_change)
		return ;
	if (keycode == LEFT || keycode == RIGHT || keycode == UP
		|| keycode == DOWN)
		ft_rotate(to_change, keycode, incr);
	if (keycode == SCALE_UP || keycode == SCALE_DOWN)
		ft_rotate(to_change, keycode, incr);
}

void	ft_diameter(double *diameter, double *radius, int keycode, double incr)
{
	if (!diameter || !radius)
		return ;
	if (keycode == SCALE_DOWN &&  *diameter > 1.0)
		ft_scale(diameter, keycode, incr);
	else if (keycode == SCALE_UP && *diameter < 50.0)
		ft_scale(diameter, keycode, incr);
	*radius = *diameter / 2.0;
}

void	ft_height(double *height, int keycode, double incr)
{
	if (!height)
		return ;
	if (keycode == SCALE_DOWN && *height > 1.0)
		ft_scale(height, keycode, incr);
	else if (keycode == SCALE_UP && *height < 50.0)
		ft_scale(height, keycode, incr);
}

void	ft_color(t_color *ref, int to_change, int keycode, int incr)
{
	if (!ref)
		return ;
	if (to_change == RED)
	{
		ft_scale_color(&ref->r, keycode, incr);
		ref->color = create_color(ref->r, ref->g, ref->b);
	}
	else if (to_change == GREEN)
	{
		ft_scale_color(&ref->g, keycode, incr);
		ref->color = create_color(ref->r, ref->g, ref->b);
	}
	else if (to_change == BLUE)
	{
		ft_scale_color(&ref->b, keycode, incr);
		ref->color = create_color(ref->r, ref->g, ref->b);
	}
}
