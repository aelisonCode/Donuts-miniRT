/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:50:33 by aelison           #+#    #+#             */
/*   Updated: 2025/02/05 15:14:44 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

/*return a vector on plan projection for the x and y coordinate*/
/*What's the position of x and y on plan projection ?*/
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

void	exec(t_scene *scene, t_vect wind)
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
		if (ptr->type == Plane)
			status *= exec_pl(scene, ptr, &r);
		if (ptr->type == Cylinder)
			status *= exec_cy(scene, ptr, &r);
		ptr = ptr->next;
	}
	if (status == EXIT_SUCCESS)
		ft_put_pixel(scene->mlx, wind.x, wind.y, scene->color_to_put);
}

void	loop_screen(t_scene *scene)
{
	t_vect	incr;

	incr.y = 0;
	while (incr.y < WINDOW_Y)
	{
		incr.x = 0;
		while (incr.x < WINDOW_X)
		{
			scene->dist_curr = -1;
			scene->color_to_put = 0X0;
			exec(scene, incr);
			incr.x++;
		}
		incr.y++;
	}
}
