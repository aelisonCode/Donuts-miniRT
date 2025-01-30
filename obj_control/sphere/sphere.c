/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:25 by aelison           #+#    #+#             */
/*   Updated: 2025/01/30 15:13:18 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_sp_event(t_scene *data, t_sp *obj, int keycode)
{
	double	incr;

	incr = 1.0;
	if (!obj)
		return ;
	if (keycode == UP)
		ft_translation(&obj->center, UP, incr);
	if (keycode == DOWN)
		ft_translation(&obj->center, DOWN, incr);
	if (keycode == LEFT)
		ft_translation(&obj->center, LEFT, incr);
	if (keycode == RIGHT)
		ft_translation(&obj->center, RIGHT, incr);
	if (keycode == Z_UP)
		ft_translation(&obj->center, Z_UP, incr);
	if (keycode == Z_DOWN)
		ft_translation(&obj->center, Z_DOWN, incr);
	if (keycode == SCALE_UP)
		ft_scale(&obj->diameter, SCALE_UP, incr);
	if (keycode == SCALE_DOWN)
		ft_scale(&obj->diameter, SCALE_DOWN, incr);
	obj->radius = obj->diameter / 2;
	gen_new_image(data);
	ft_launch(data);
}

int	ft_intersec_sp(t_sp *obj, t_ray *r, t_vect *solution)
{
	double	a;
	double	b;
	double	c;
	t_vect	dist;
	double	discriminant;

	dist = substraction(r->origin, obj->center);
	a = scalaire(r->direction, r->direction);
	b = 2 * scalaire(r->direction, dist);
	c = scalaire(dist, dist) - pow(obj->radius, 2);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (EXIT_FAILURE);
	if (solution != NULL)
	{
		if (get_racine(a, b, discriminant) < 0)
			return (EXIT_FAILURE);
		*solution = compute_intersec_pts(r, get_racine(a, b, discriminant));
	}
	return (EXIT_SUCCESS);
}

static double	lambertienne_reflection_sp(double coeff_reflection, t_l *light,
		t_vect *center, t_vect point)
{
	t_vect	v_normal;
	t_vect	v_light;
	double	scal;
	double	res;
	int		x;

	x = 0;
	v_normal = ft_normalize(substraction(point, *center));
	v_light = ft_normalize(substraction(light->pos, point));
	scal = scalaire(v_normal, v_light);
	if (scal < 0)
		scal = 0;
	res = coeff_reflection * scal * light->bright;
	return (res);
}

static int	get_sp_color(t_scene *s, t_maps *start, t_vect *point)
{
	int		res;
	int		shadow;
	double	lambert;
	t_sp	*sphere;

	sphere = start->struct_obj;
	lambert = lambertienne_reflection_sp(COEFF_REFCT, s->light, &sphere->center,
			*point);
	res = gen_color(sphere->color.color, s->amlight, lambert, REFRACTION_AM);
	shadow = ft_add_shadow(s, start->next, point, sphere->color.color);
	if (shadow != -1)
		res = shadow;
	return (res);
}

int	exec_sp(t_scene *s, t_maps *curr, t_ray *r, t_vect wind)
{
	int		res;
	int		color;
	t_vect	solution;

	res = EXIT_FAILURE;
	(void)wind;
	if (ft_intersec_sp(curr->struct_obj, r, &solution) == EXIT_SUCCESS)
	{
		res = EXIT_SUCCESS;
		color = get_sp_color(s, curr, &solution);
		cmp_dist(s, &solution, color);
		ft_put_pixel(s->mlx, wind.x, wind.y, color);
	}
	return (res);
}
