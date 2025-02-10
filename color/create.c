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
	else if (keycode == SCALE_DOWN && *color_base > 0)
		*color_base -= incr;
}

double	create_ambient(t_a *ambient, double color)
{
	double	res;

	res = ambient->ratio * color * REFRACTION_AM;
	return (res);
}
/*  */
/* double	create_diffuse(int color, double ref_diff) */
/* { */
/* 	double	res; */
/*  */
/* 	res = ref_diff * color; */
/* 	return (res); */
/* } */
/*  */
/* double shadow(t_l l, t_vect inter, t_vect inter_obj) */
/* { */
/* 	double	d_o; */
/* 	double	d_s; */
/* 	double	res; */
/* 	d_o = distances(l.pos, inter); */
/* 	d_s = distances(l.pos, inter_obj); */
/* 	res = subpow(d_s, d_o) / pow(d_o, 2); */
/* 	return (res); */
/* } */
/*  */
/* double	create_shadow(t_l l, t_vect inter, t_vect inter_obj) */
/* { */
/* 	double res; */
/* 	double d_o; */
/* 	double s; */
/*  */
/* 	d_o = vect_lenght(substraction(l.pos, inter)); */
/* 	s = shadow(l, inter, inter_obj); */
/* 	res = (1 - s) * ((l.bright) / pow(d_o, 2)); */
/* 	return (res); */
/* } */

int	gen_color(int color, t_a *am, double lambert)
{
	double	red;
	double	green;
	double	blue;
	double	res;
	double	ambient;

	ambient = create_ambient(am, get_red(color) / 255.0);
	red = ambient + (lambert * get_red(color) / 255.0);
	if (red > 1)
		red = 1;
	ambient = create_ambient(am, get_green(color) / 255.0);
	green = ambient + (lambert * get_green(color) / 255.0);
	if (green > 1)
		green = 1;
	ambient = create_ambient(am, get_blue(color) / 255.0);
	blue = ambient + (lambert * get_blue(color) / 255.0);
	if (blue > 1)
		blue = 1;
	res = create_color(red * 255.0, green * 255.0, blue * 255.0);
	return (res);
}
