/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:47 by aelison           #+#    #+#             */
/*   Updated: 2025/02/07 11:16:43 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"
/**/
/* static t_vect	get_dir(t_maps *curr, t_vect pts) */
/* { */
/* 	t_vect	res; */
/* 	t_sp	*tmp_sp; */
/* 	t_cy	*tmp_cy; */
/**/
/* 	res = init_vect(1, 1, 1); */
/* 	if (curr->type == Sphere) */
/* 	{ */
/* 		tmp_sp = (t_sp *)curr->struct_obj; */
/* 		res = init_vect(tmp_sp->center.x, tmp_sp->center.y, tmp_sp->center.z); */
/* 		res = ft_normalize(substraction(pts, res)); */
/* 		return (res); */
/* 	} */
/* 	if (curr->type == Cylinder) */
/* 	{ */
/* 		tmp_cy = (t_cy *)curr->struct_obj; */
/* 		res = init_vect(tmp_cy->center.x, tmp_cy->center.y, tmp_cy->center.z); */
/* 		res = ft_normalize(substraction(pts, res)); */
/* 		return (res); */
/* 	} */
/* 	return (res); */
/* } */
/**/
/* static int	is_in_view(t_ray r, t_vect pts, t_maps *curr) */
/* { */
/* 	t_vect	dir; */
/**/
/* 	dir = get_dir(curr, pts); */
/* 	if (scalaire(r.direction, dir) < 0) */
/* 		return (EXIT_FAILURE); */
/* 	return (EXIT_SUCCESS); */
/* } */
/**/
/* int	check_sp(t_scene *s, t_sp *obj, t_vect *ref_pts, t_maps *target) */
/* { */
/* 	int		res; */
/* 	double	t; */
/* 	t_vect	point; */
/* 	t_ray	r; */
/**/
/* 	res = -1; */
/* 	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z); */
/* 	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts)); */
/* 	if (ft_intersec_sp(obj, &r, &point, &t) == EXIT_SUCCESS) */
/* 	{ */
/* 		if (vect_lenght(substraction(s->light->pos, */
/* 					*ref_pts)) > vect_lenght(substraction(s->light->pos, */
/* 					point))) */
/* 		{ */
/* 			res = gen_color(obj->color.color, s->amlight, EPSILON, EPSILON); */
/* 			if (target->type == Plane) */
/* 				return (res); */
/* 			if (is_in_view(r, *ref_pts, target) == EXIT_FAILURE) */
/* 				res = -1; */
/* 		} */
/* 	} */
/* 	return (res); */
/* } */
/**/
/* int	check_pl(t_scene *s, t_pl *obj, t_vect *ref_pts, t_maps *target) */
/* { */
/* 	int		res; */
/* 	double	t; */
/* 	t_vect	point; */
/* 	t_ray	r; */
/**/
/* 	(void)target; */
/* 	res = -1; */
/* 	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z); */
/* 	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts)); */
/* 	if (ft_intersec_pl(obj, &r, &point, &t) == EXIT_SUCCESS) */
/* 	{ */
/* 		if (vect_lenght(substraction(s->light->pos, */
/* 					*ref_pts)) > vect_lenght(substraction(s->light->pos, */
/* 					point))) */
/* 			res = gen_color(obj->color.color, s->amlight, EPSILON, EPSILON); */
/* 	} */
/* 	return (res); */
/* } */
/**/
/* int	check_cy(t_scene *s, t_cy *obj, t_vect *ref_pts, t_maps *target) */
/* { */
/* 	int		res; */
/* 	double	t; */
/* 	t_vect	point; */
/* 	t_ray	r; */
/**/
/* 	res = -1; */
/* 	r.origin = init_vect(ref_pts->x, ref_pts->y, ref_pts->z); */
/* 	r.direction = ft_normalize(substraction(s->light->pos, *ref_pts)); */
/* 	if (ft_intersec_cy(obj, &r, &point, &t) == EXIT_SUCCESS) */
/* 	{ */
/* 		if (vect_lenght(substraction(s->light->pos, */
/* 					*ref_pts)) > vect_lenght(substraction(s->light->pos, */
/* 					point))) */
/* 		{ */
/* 			res = gen_color(obj->color.color, s->amlight, EPSILON, EPSILON); */
/* 			if (target->type == Plane) */
/* 				return (res); */
/* 			if (is_in_view(r, *ref_pts, target) == EXIT_FAILURE) */
/* 				res = -1; */
/* 		} */
/* 	} */
/* 	return (res); */
/* } */
