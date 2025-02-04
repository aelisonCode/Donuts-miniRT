/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:09:10 by nyrandri          #+#    #+#             */
/*   Updated: 2025/02/04 09:24:08 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"
#include "../../header/vector.h"

void	rotate_on_z(double ratio_deg, t_cy *obj)
{
	t_vect	res;
	t_vect	v;
	double	ratio_rad;

	ratio_rad = ratio_deg * (M_PI / 180);
	v = ft_normalize(obj->direction);
	res.x = v.x * cos(ratio_rad) - v.y * sin(ratio_rad);
	res.y = v.x * sin(ratio_rad) + v.y * cos(ratio_rad);
	res.z = v.z;
	obj->direction = ft_normalize(res);
}

void	ft_cy_event(t_scene *s, t_cy *obj, int keycode, double incr)
{
	if (s->do_rotation == FALSE)
	{
		if (keycode == LEFT || keycode == RIGHT)
			ft_translation(&obj->center, keycode, incr);
		if (keycode == UP || keycode == DOWN)
			ft_translation(&obj->center, keycode, incr);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_translation(&obj->center, keycode, incr);
	}
	else if (s->do_rotation == TRUE)
	{
		if (keycode == LEFT || keycode == RIGHT)
			ft_rotate(&obj->direction, keycode, incr);
		if (keycode == UP || keycode == DOWN)
			ft_rotate(&obj->direction, keycode, incr);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_rotate(&obj->direction, keycode, incr);
	}
	if (keycode == SCALE_UP || keycode == SCALE_DOWN)
		ft_scale(&obj->diameter, keycode, incr);
	obj->radius = obj->diameter / 2;
	gen_new_image(s);
	ft_launch(s);
}
