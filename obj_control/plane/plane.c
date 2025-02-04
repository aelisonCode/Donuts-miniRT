/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:25:45 by aelison           #+#    #+#             */
/*   Updated: 2025/02/04 08:23:42 by aelison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	ft_pl_event(t_scene *s, t_pl *obj, int keycode, double incr)
{
	if (!s)
		return ;
	if (s->do_rotation == FALSE)
	{
		if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
			ft_translation(&obj->direction, keycode, incr);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_translation(&obj->direction, keycode, incr);
	}
	else if (s->do_rotation == TRUE)
	{
		if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
			ft_rotate(&obj->direction, keycode, 10);
		if (keycode == Z_UP || keycode == Z_DOWN)
			ft_rotate(&obj->direction, keycode, 10);
	}
	gen_new_image(s);
	ft_launch(s);
}

int	ft_intersec_pl(t_pl *obj, t_ray *ray, t_vect *res, double *t)
{
	double	denominator;
	t_vect	x;

	denominator = scalaire(ray->direction, ft_normalize(obj->direction));
	if (fabs(denominator) < 1e-4)
		return (EXIT_FAILURE);
	x = substraction(obj->point, ray->origin);
	*t = scalaire(x, ft_normalize(obj->direction)) / denominator;
	if (*t >= 0)
	{
		*res = compute_intersec_pts(ray, *t);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

static double	lambertienne_reflection_pl(double coeff_reflection, t_l *light,
		t_pl *obj, t_vect point)
{
	t_vect	v_normal;
	t_vect	v_light;
	double	scal;
	double	res;

	v_normal = ft_normalize(obj->direction);
	v_light = ft_normalize(substraction(light->pos, point));
	scal = scalaire(v_normal, v_light);
	if (scal < 0)
		scal = 0;
	res = coeff_reflection * scal * light->bright;
	return (res);
}

static int	get_pl_color(t_scene *s, t_maps *start, t_vect *point)
{
	int		res;
	int		shadow;
	double	lambert;
	t_pl	*plane;

	plane = start->struct_obj;
	lambert = lambertienne_reflection_pl(COEFF_REFCT, s->light, plane, *point);
	res = gen_color(plane->color.color, s->amlight, lambert, REFRACTION_AM);
	shadow = ft_add_shadow(s, start, point);
	if (shadow != -1)
		res = shadow;
	return (res);
}

int	exec_pl(t_scene *s, t_maps *obj, t_ray *r)
{
	int		res;
	double	t;
	t_vect	solution;

	res = EXIT_FAILURE;
	if (ft_intersec_pl(obj->struct_obj, r, &solution, &t) == EXIT_SUCCESS)
	{
		res = EXIT_SUCCESS;
		obj->color = get_pl_color(s, obj, &solution);
		cmp_dist(s, t, obj->color);
	}
	return (res);
}
