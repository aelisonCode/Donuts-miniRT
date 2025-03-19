/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:23:54 by aelison           #+#    #+#             */
/*   Updated: 2025/03/06 14:31:28 by aelison          ###   ########.fr       */
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

t_ray	create_ray(t_vect *origin, t_projection *p, int x, int y)
{
	t_ray	res;
	t_vect	point;

	point = compute_point(p, x, y);
	res.origin = init_vect(origin->x, origin->y, origin->z);
	res.direction = ft_normalize(substraction(point, *origin));
	return (res);
}

static void	ft_make_image(t_scene *s, t_vect wind, int step, int color)
{
	int		tmp_y;
	double	tmp_x;
	int		tmp_step;

	tmp_y = step;
	tmp_x = wind.x;
	tmp_step = step;
	while (tmp_y)
	{
		wind.x = tmp_x;
		step = tmp_step;
		while (step)
		{
			ft_put_pixel(s->mlx, wind.x, wind.y, color);
			wind.x++;
			step--;
		}
		wind.y++;
		tmp_y--;
	}
}

void	ft_compute_color(t_scene *scene, t_vect wind, int step, t_ray *r)
{
	t_color	to_put;

	to_put = get_col(scene->nearest_obj);
	if (ft_is_a_shadow(scene, scene->nearest_obj, r) == TRUE)
		to_put.color = ambient_color(&to_put, scene);
	else
	{
		if (ft_cam_pos(scene->nearest_obj, scene, r) == FALSE)
			to_put.color = ambient_color(&to_put, scene);
		else
			to_put.color = diffus_color(&to_put, scene->light, scene, r);
	}
	if (scene->pixelize == FALSE)
		ft_put_pixel(scene->mlx, wind.x, wind.y, to_put.color);
	else
		ft_make_image(scene, wind, step, to_put.color);
}

void	exec(t_scene *scene, t_vect wind, int step)
{
	t_maps	*ptr;
	t_ray	r;
	int		status;

	ptr = scene->world;
	status = EXIT_FAILURE;
	r = create_ray(&scene->cam->view_point, scene->p, wind.x, wind.y);
	while (ptr)
	{
		if (ptr->type == Sphere)
			status *= exec_sp(scene, ptr, &r);
		else if (ptr->type == Plane)
			status *= exec_pl(scene, ptr, &r);
		else if (ptr->type == Cylinder)
			status *= exec_cy(scene, ptr, &r);
		ptr = ptr->next;
	}
	if (status == EXIT_SUCCESS && scene->nearest_obj)
		ft_compute_color(scene, wind, step, &r);
}
