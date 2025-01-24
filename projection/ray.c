/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 07:46:44 by aelison           #+#    #+#             */
/*   Updated: 2025/01/24 07:46:56 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	compute_point(t_projection p, int x, int y)
{
	t_vect	res;
	t_vect	plan_pos;
	t_vect	hztal_offset;
	t_vect	vtcal_offset;

	plan_pos.x = (double)x / WINDOW_X;
	plan_pos.y = (double)y / WINDOW_Y;
	plan_pos.z = 1;
	hztal_offset = vect_dot_val(p.width_dir, plan_pos.x * p.width);
	vtcal_offset = vect_dot_val(p.height_dir, plan_pos.y * p.height);
	res = sum(sum(p.top_left, hztal_offset), vect_dot_val(vtcal_offset, -1));
	return (res);
}

t_ray	create_ray(t_c *cam, t_projection p, int x, int y)
{
	t_ray	res;
	t_vect	point;

	point = compute_point(p, x, y);
	res.origin = cam->view_point;
	res.direction = ft_normalize(substraction(point, cam->view_point));
	return (res);
}

void	test_sp(t_sp *obj, t_mlx *mlx, t_ray r)
{
	int		val;
	double	racine;
	t_vect	intersect;

	val = ft_intersec_sp(obj, &r, &racine);
	if (val == EXIT_FAILURE)
		ft_printf("No intersection find\n");
	else
	{
		ft_printf("Find intersection !\n");
		intersect.x = r.origin.x + racine * r.direction.x;
		intersect.y = r.origin.y + racine * r.direction.y;
		intersect.z = r.origin.z + racine * r.direction.z;
		ft_put_pixel(mlx, intersect.x, intersect.y, 0XFF0000);
	}
}

void	send_ray(t_mlx *mlx, t_projection p, t_c *cam, t_sp *obj)
{
	double	x;
	double	y;
	t_ray	r;

	y = 0;
	while (y < p.height)
	{
		x = 0;
		while (x < p.width)
		{
			// ft_put_pixel(mlx, x, y, 0XFF0000);
			r = create_ray(cam, p, x, y);
			test_sp(obj, mlx, r);
			x++;
		}
		y++;
	}
}
