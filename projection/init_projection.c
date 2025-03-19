/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:12:31 by aelison           #+#    #+#             */
/*   Updated: 2025/01/24 07:27:13 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	dir_hzontal(t_vect cam_dir)
{
	t_vect	tmp;
	t_vect	res;

	tmp = init_vect(0, 1, 0);
	if (fabs(cam_dir.y) >= 1)
		tmp = init_vect(1, 0, 0);
	res = cross(cam_dir, tmp);
	return (res);
}

t_vect	dir_vtcal(t_vect cam_dir, t_vect dir_vtcal)
{
	t_vect	res;

	res = cross(cam_dir, dir_vtcal);
	return (res);
}

t_vect	get_originleft_plan(t_vect view_point, t_vect c_dir, t_projection p,
		double dist)
{
	t_vect	center;
	t_vect	up;
	t_vect	go_left;
	t_vect	res;

	center = substraction(view_point, vect_dot_val(c_dir, dist));
	up = sum(center, vect_dot_val(p.height_dir, p.height / 2));
	go_left = substraction(up, vect_dot_val(p.width_dir, p.width / 2));
	res = go_left;
	return (res);
}

t_projection	*init_pjct(t_c *cam, double dist)
{
	t_projection	*res;
	t_vect			view_dir;
	t_vect			d_vtcal;
	t_vect			d_hzontal;

	res = malloc(sizeof(t_projection));
	if (!res)
		return (NULL);
	res->height = 2 * dist * tan(cam->fov / 2 * M_PI / 180);
	res->width = res->height * cam->ratio;
	view_dir = ft_normalize(cam->direction);
	d_hzontal = ft_normalize(dir_hzontal(view_dir));
	d_vtcal = ft_normalize(dir_vtcal(view_dir, d_hzontal));
	res->width_dir = vect_dot_val(d_hzontal, -1);
	res->height_dir = vect_dot_val(d_vtcal, -1);
	res->top_left = get_originleft_plan(cam->view_point, view_dir, *res, dist);
	return (res);
}
