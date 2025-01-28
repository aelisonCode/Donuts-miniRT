/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:50:33 by aelison           #+#    #+#             */
/*   Updated: 2025/01/28 14:13:35 by aelison          ###   ########.fr       */
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

/*create ray between param to the point*/
/*EX: Camera to point o plan projection*/
t_ray	create_ray(t_vect *origin, t_projection *p, int x, int y)
{
	t_ray	res;
	t_vect	point;

	point = compute_point(p, x, y);
	res.origin = init_vect(origin->x, origin->y, origin->z);
	res.direction = ft_normalize(substraction(point, *origin));
	return (res);
}

double	lambertienne_reflection(double coeff_reflection, t_l *light,
		t_vect *center, t_vect point)
{
	t_vect	v_normal;
	t_vect	v_light;
	double	scal;
	double	res;

	v_normal = ft_normalize(substraction(point, *center));
	v_light = ft_normalize(substraction(light->pos, point));
	scal = scalaire(v_normal, v_light);
	if (scal < 0)
		scal = 0;
	res = coeff_reflection * scal * light->bright;
	return (res);
}

void	exec(t_scene *scene, t_maps *ptr, int x, int y)
{
	int		color;
	t_ray	r;
	t_ray	cam;

	color = 0X000000;
	cam.origin = init_vect(scene->cam->view_point.x, scene->cam->view_point.y,
			scene->cam->view_point.z);
	cam.direction = init_vect(scene->cam->direction.x, scene->cam->direction.y,
			scene->cam->direction.z);
	r = create_ray(&cam.origin, scene->p, x, y);
	if (ptr->type == Sphere)
		color = exec_sp(scene, ptr->struct_obj, &r);
	else if (ptr->type == Cylinder)
		color = exec_cy(scene, ptr->struct_obj, &r);
	ft_put_pixel(scene->mlx, x, y, color);
}

void	loop_screen(t_scene *scene, t_maps *obj)
{
	double	x;
	double	y;

	y = 0;
	while (y < WINDOW_Y)
	{
		x = 0;
		while (x < WINDOW_X)
		{
			exec(scene, obj, x, y);
			x++;
		}
		y++;
	}
}
