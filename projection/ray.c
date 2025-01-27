/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 07:46:44 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 14:03:12 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	compute_point(t_projection *p, int x, int y)
{
	t_vect	res;
	t_vect	plan_pos;
	t_vect	hztal_offset;
	t_vect	vtcal_offset;

	plan_pos.x = (double)x / WINDOW_X;
	plan_pos.y = (double)y / WINDOW_Y;
	plan_pos.z = 1;
	hztal_offset = vect_dot_val(p->width_dir, plan_pos.x * p->width);
	vtcal_offset = vect_dot_val(p->height_dir, plan_pos.y * p->height);
	res = sum(sum(p->top_left, hztal_offset), vect_dot_val(vtcal_offset, -1));
	return (res);
}

t_ray	create_ray(t_c *cam, t_projection *p, int x, int y)
{
	t_ray	res;
	t_vect	point;

	point = compute_point(p, x, y);
	res.origin = cam->view_point;
	res.direction = ft_normalize(substraction(point, cam->view_point));
	return (res);
}

void	send_ray(t_scene *scene, void *obj)
{
	int		color;
	double	x;
	double	y;
	t_ray	r;

	y = 0;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			r = create_ray(scene->cam, scene->p, x, y);
			color = exec_sp(scene, obj, &r);
			ft_put_pixel(scene->mlx, x, y, color);
			x++;
		}
		y++;
	}
}
