/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:25 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 15:43:28 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_sp_event(t_scene *data, t_maps *curr, int keycode, double incr)
{
	t_sp	*tmp;

	if (!data || !curr)
		return ;
	tmp = curr->struct_obj;
	if (data->do_color != FALSE && (keycode == SCALE_UP
			|| keycode == SCALE_DOWN))
		ft_color(&tmp->color, data->do_color, keycode, 5);
	if (data->do_diameter == TRUE)
		ft_diameter(&tmp->diameter, &tmp->radius, keycode, incr);
	if (data->do_z == TRUE)
		ft_center(&tmp->center, keycode, incr + 1.5);
	gen_new_image(data);
	ft_launch(data);
}

int	ft_intersec_sp(t_sp *obj, t_ray *r, t_vect *solution, double *t)
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
		*t = get_root(a, b, discriminant, &obj->t2);
		obj->t1 = *t;
		if (*t < 0)
			return (EXIT_FAILURE);
		*solution = compute_intersec_pts(r, *t);
	}
	return (EXIT_SUCCESS);
}

static double	lambertienne_reflection_sp(t_sp *obj, t_l *light, t_vect *point)
{
	t_vect	v_light;
	double	scal;
	double	res;

	v_light = ft_normalize(substraction(light->pos, *point));
	scal = scalaire(obj->v_normal, v_light);
	if (scal < 0)
		scal = 0;
	res = COEFF_REFCT * scal * light->bright;
	return (res);
}

static int	get_sp_color(t_scene *s, t_maps *start, t_vect *point)
{
	int		res;
	int		shadow;
	double	lambert;
	t_sp	*sphere;

	sphere = start->struct_obj;
	lambert = lambertienne_reflection_sp(start->struct_obj, s->light, point);
	res = gen_color(sphere->color.color, s->amlight, lambert, REFRACTION_AM);
	shadow = ft_add_shadow(s, start, point, lambert);
	if (shadow != -1)
		res = shadow;
	return (res);
}

int	exec_sp(t_scene *s, t_maps *curr, t_ray *r)
{
	t_sp	*obj;
	double	t;
	t_vect	solution;

	if (!s || !curr || !r)
		return (EXIT_FAILURE);
	obj = curr->struct_obj;
	if (ft_intersec_sp(obj, r, &solution, &t) == EXIT_SUCCESS)
	{
		obj->v_normal = ft_normalize(substraction(solution, obj->center));
		curr->color = get_sp_color(s, curr, &solution);
		cmp_dist(s, t, curr->color);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
