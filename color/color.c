/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:34:28 by aelison           #+#    #+#             */
/*   Updated: 2025/03/06 15:57:15 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_exec_color(t_scene *s, int keycode, int incr, t_color *to_change)
{
	if (ft_get_event_state(s->event, red) == TRUE)
		ft_scale_color(&to_change->r, keycode, incr);
	if (ft_get_event_state(s->event, green) == TRUE)
		ft_scale_color(&to_change->g, keycode, incr);
	if (ft_get_event_state(s->event, blue) == TRUE)
		ft_scale_color(&to_change->b, keycode, incr);
}

void	ft_scale_color(int *color_base, int keycode, int incr)
{
	if (!color_base)
		return ;
	if (keycode == SCALE_UP && *color_base < 255)
	{
		*color_base += incr;
		if (*color_base > 255)
			*color_base = 255;
	}
	else if (keycode == SCALE_DOWN && *color_base > 0)
	{
		*color_base -= incr;
		if (*color_base < 0)
			*color_base = 0;
	}
}

int	create_color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

double	ambient(int c, t_scene *s, int a_c)
{
	double	res;

	res = (s->amlight->ratio * (a_c / 255.0) * REFRACTION_AM * (c / 255.0));
	return (res);
}

int	ambient_color(t_color *c, t_scene *s)
{
	int		res;
	double	r;
	double	g;
	double	b;

	r = fmin(1, ambient(c->r, s, s->amlight->color.r));
	g = fmin(1, ambient(c->g, s, s->amlight->color.g));
	b = fmin(1, ambient(c->b, s, s->amlight->color.b));
	res = create_color(r * 255, g * 255, b * 255);
	return (res);
}
