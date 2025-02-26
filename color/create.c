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

#include "../header/mini_rt.h"

void	ft_scale_color(int *color_base, int keycode, int incr)
{
	if (!color_base)
		return ;
	if (keycode == SCALE_UP && *color_base < 255)
		*color_base += incr;
	else if (keycode == SCALE_DOWN && *color_base > 0)
		*color_base -= incr;
}
/*================== Start V2 =======================*/
/*V2 diffuse_reflection : Lambertienne*/
/*To apply to each object*/
double	brightness_reflection(t_l light, t_vect v_normal, t_vect point)
{
	t_vect v_light;
	double	tmp;

	v_light = ft_normalize(substraction(light.pos, point));

	tmp = fmin(scalaire(v_light, v_normal), 0);
	return (light.bright *  COEFF_REFCT * tmp);
}

/*V2 apply brightness_reflection to each color*/
double diff_reflect(double bright, int color)
{
	return (bright * (color / 255.0));
}

/*V2 ambient color*/
double	am_reflect(double am_ratio, int color)
{
	return (am_ratio * (color / 255.0) * REFRACTION_AM);
}

/* ================ End V2 ================== */
double	create_ambient(t_a *ambient, double color)
{
	double	res;

	res = ambient->ratio * color * REFRACTION_AM;
	return (res);
}

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
