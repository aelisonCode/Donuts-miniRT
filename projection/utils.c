/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:26:05 by aelison           #+#    #+#             */
/*   Updated: 2025/03/06 14:31:32 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	ft_shadow_sp(t_sp *obj, t_scene *s, t_ray *r)
{
	t_vect	normal_obj;
	t_vect	cam_to_obj;
	t_vect	point;

	point = compute_intersec_pts(r, s->tmp_dist);
	normal_obj = ft_normalize(substraction(point, obj->center));
	cam_to_obj = ft_normalize(substraction(point, s->cam->view_point));
	if (scalaire(normal_obj, cam_to_obj) < 0)
		return (TRUE);
	return (FALSE);
}

static int	ft_shadow_pl(t_pl *obj, t_scene *s, t_ray *r)
{
	t_vect	normal_obj;
	t_vect	cam_to_obj;
	t_vect	point;

	point = compute_intersec_pts(r, s->tmp_dist);
	normal_obj = obj->direction;
	cam_to_obj = ft_normalize(substraction(point, s->cam->view_point));
	if (scalaire(normal_obj, cam_to_obj) < 0)
		return (TRUE);
	return (FALSE);
}

static int	ft_shadow_cy(t_cy *obj, t_scene *s, t_ray *r)
{
	t_vect	normal_obj;
	t_vect	cam_to_obj;
	t_vect	point;

	point = compute_intersec_pts(r, s->tmp_dist);
	normal_obj = ft_normal_cy(r, obj, s->tmp_dist, point);
	cam_to_obj = ft_normalize(substraction(point, s->cam->view_point));
	if (scalaire(normal_obj, cam_to_obj) < 0)
		return (TRUE);
	return (FALSE);
}

int	ft_cam_pos(t_maps *nearest, t_scene *s, t_ray *r)
{
	if (!nearest || !s)
		return (FALSE);
	if (nearest->type == Plane)
		return (ft_shadow_pl(nearest->struct_obj, s, r));
	if (nearest->type == Sphere)
		return (ft_shadow_sp(nearest->struct_obj, s, r));
	if (nearest->type == Cylinder)
		return (ft_shadow_cy(nearest->struct_obj, s, r));
	return (FALSE);
}
