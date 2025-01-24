/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:25 by aelison           #+#    #+#             */
/*   Updated: 2025/01/23 09:22:47 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mini_rt.h"

void	draw_sphere(t_mlx *mlx, t_sp *obj)
{
	double	r_carre;
	double	tmp;
	t_vect	ctre;
	int		step_x;
	int		step_y;

	ctre = obj->center;
	r_carre = pow(obj->radius, 2);
	step_x = ctre.x - obj->radius;
	while (step_x <= ctre.x + obj->radius)
	{
		step_y = ctre.y - obj->radius;
		while (step_y <= ctre.y + obj->radius)
		{
			tmp = r_carre - (step_x - ctre.x) * (step_x - ctre.x) - (step_y
					- ctre.y) * (step_y - ctre.y);
			if (tmp >= 0)
				ft_put_pixel(mlx, step_x, step_y, 0XFF0000);
			step_y++;
		}
		step_x++;
	}
}

int	ft_intersec_sp(t_sp *obj, t_ray *r, double *solution)
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
	discriminant = pow(b, 2) - (4 * a * c);
	printf("discri = %f\n", discriminant);
	if (discriminant < 0)
		return (EXIT_FAILURE);
	*solution = get_racine(a, b, discriminant);
	if (*solution < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	go_sphere(t_mlx *mlx, t_sp *obj)
{
	t_vect	tmp;
	t_vect	intersect;
	t_ray	r;
	double	racine;
	int		val;

	racine = 0;
	r.origin = init_vect(0, 0, 0);
	ft_put_pixel(mlx, r.origin.x, r.origin.y, 0XFFFFFF);
	tmp = substraction(obj->center, r.origin);
	r.direction = ft_normalize(tmp);
	ft_put_pixel(mlx, obj->center.x, obj->center.y, 0X0000FF);
	val = ft_intersec_sp(obj, &r, &racine);
	if (val == EXIT_FAILURE)
		ft_printf("Pas d'intersection\n");
	else
	{
		ft_printf("Find intersection !\n");
		intersect.x = r.origin.x + racine * r.direction.x;
		intersect.y = r.origin.y + racine * r.direction.y;
		intersect.z = r.origin.z + racine * r.direction.z;
		ft_put_pixel(mlx, intersect.x, intersect.y, 0XFF0000);
	}
}
