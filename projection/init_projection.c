/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:12:31 by aelison           #+#    #+#             */
/*   Updated: 2025/01/23 15:26:23 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.h"

/*Orientation horizontal de la camera*/
t_vect	dir_hzontal(t_vect	cam_dir)
{
	t_vect	tmp;
	t_vect	res;

	tmp = init_vect(0, 1, 0);
	res = dot(cam_dir, tmp);
	return (res);
}

/*Orientation vertical de la camera*/
t_vect	dir_vtcal(t_vect cam_dir, t_vect dir_vtcal)
{
	t_vect	res;

	res = dot(cam_dir, dir_vtcal);
	return (res);
}

/*dist = distance entre camera et plan de projection*/
//ici definie sur 1
t_projection	init_pjct(t_c cam, double dist)
{
	t_projection	res;
	t_vect			view_dir;
	t_vect			d_vtcal;
	t_vect			d_hzontal;

	res.height = 2 * dist * tan(cam.fov / 2);
	res.width = res.height * cam.ratio;
	view_dir = ft_normalize(cam.direction);
	d_hzontal = dir_hzontal(cam.direction);
	d_vtcal = dir_vtcal(cam.direction, d_hzontal);
	res.top_left = init_vect(0, 0, 0);
	res.width_dir = d_hzontal;
	res.height_dit = d_vtcal;
	return (res);
}
