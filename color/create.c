/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:34:52 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 15:17:28 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/color.h"
#include "../header/struct.h"

void	ft_scale_color(int *color_base, int keycode, int incr)
{
	if (!color_base)
		return ;
	if (keycode == SCALE_UP && *color_base < 255)
		*color_base += incr;
	if (keycode == SCALE_DOWN && *color_base > 0)
		*color_base -= incr;
}

double	create_ambient(t_a *ambient, double reflect_am, double color)
{
	double	res;

	res = ambient->ratio * reflect_am * color;
	return (res);
}

int	gen_color(int color, t_a *am, double lambert, double reflect)
{
	double	red;
	double	green;
	double	blue;
	double	res;
	double	ambient;

	ambient = create_ambient(am, reflect, get_red(color) / 255.0);
	red = ambient + (lambert * get_red(color) / 255.0);
	if (red > 1)
		red = 1;
	ambient = create_ambient(am, reflect, get_green(color) / 255.0);
	green = ambient + (lambert * get_green(color) / 255.0);
	if (green > 1)
		green = 1;
	ambient = create_ambient(am, reflect, get_blue(color) / 255.0);
	blue = ambient + (lambert * get_blue(color) / 255.0);
	if (blue > 1)
		blue = 1;
	res = create_color(red * 255.0, green * 255.0, blue * 255.0);
	return (res);
}
