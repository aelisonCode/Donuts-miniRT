/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_effect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:39:02 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/28 13:21:00 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/color.h"
#include "../header/mini_rt.h"

int	lamber_color(t_color *c, t_scene *s, t_vect l, t_vect surf)
{
	double	r;
	double	g;
	double	b;
	t_l		*light;
	int		res;

	light = s->light;
	r = (light->color.r / 255.0) * light->bright * (c->r / 255.0) * fmax(0,
			(scalaire(surf, l))) + ambient(c->r, s, s->amlight->color.r);
	g = (light->color.g / 255.0) * light->bright * (c->g / 255.0) * fmax(0,
			(scalaire(surf, l))) + ambient(c->g, s, s->amlight->color.g);
	b = (light->color.b / 255.0) * light->bright * (c->b / 255.0) * fmax(0,
			(scalaire(surf, l))) + ambient(c->b, s, s->amlight->color.b);
	r = fmin(1, r);
	g = fmin(1, g);
	b = fmin(1, b);
	res = create_color(r * 255, g * 255, b * 255);
	return (res);
}

int	diffus_color(t_color *c, t_l *light, t_scene *s, t_ray *r)
{
	int		res;
	t_vect	l;
	t_vect	inter;
	t_vect	surf;

	surf = init_vect(1, 1, 1);
	inter = compute_intersec_pts(r, s->tmp_dist);
	l = ft_normalize(substraction(light->pos, inter));
	if (s->nearest_obj->type == Sphere)
		surf = normal_sp(inter, s->nearest_obj->struct_obj);
	else if (s->nearest_obj->type == Cylinder)
		surf = ft_normal_cy(r, s->nearest_obj->struct_obj, s->tmp_dist, inter);
	else if (s->nearest_obj->type == Plane)
		surf = normal_pl(s->nearest_obj->struct_obj);
	res = lamber_color(c, s, l, surf);
	return (res);
}
