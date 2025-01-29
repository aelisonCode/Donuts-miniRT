/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:25:45 by aelison           #+#    #+#             */
/*   Updated: 2025/01/29 09:50:54 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

double calcul(double cross, double x_one, double x_two)
{
	double res;

	res = cross * (x_one - x_two);
	return (res);
}

t_vect cross_double(t_vect x, double y)
{
	t_vect res;

	res.x = x.x * y;
	res.y = x.y * y;
	res.z = x.z * y;
	return (res);
}

int ft_intersec_pl(t_pl *obj, t_ray *ray, double *res)
{
	double denominator;
	t_vect x;

	denominator = scalaire(ray->direction, ft_normalize(obj->direction));
	if (fabs(denominator) < 1e-4)
		return (EXIT_FAILURE);
	x = substraction(obj->point, ray->origin);
	*res = scalaire(x, ft_normalize(obj->direction)) / denominator;
	if (*res >= 0)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

double	lambertienne_reflection_pl(double coeff_reflection, t_l *light,
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

int	exec_pl(t_scene *s, t_pl *obj, t_ray *r, int x, int y)
{
	int		res;
	double	solution;
	double	lambert;
	t_vect	point;

	res = 0X000000;
	if (ft_intersec_pl(obj, r, &solution) == EXIT_SUCCESS)
	{
		point = sum(r->origin, vect_dot_val(r->direction, solution));
		lambert = lambertienne_reflection_pl(COEFF_REFCT, s->light, obj, point);
		res = gen_color(obj->color.color, s->amlight, lambert, REFRACTION_AM);
		ft_put_pixel(s->mlx, x, y, res);
	}
	return (res);
}
