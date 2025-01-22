/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:51 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 13:41:35 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	dda_algo(t_mlx *mlx, t_vect start, t_vect goal)
{
	t_vect	diff;
	double	inc;
	double	step_x;
	double	step_y;
	double	i;

	i = 0;
	diff = init_vect(goal.x - start.x, goal.y - start.y, goal.z - start.z);
	inc = 0;
	if (fabs(diff.x) > fabs(diff.y))
		inc = fabs(diff.x);
	else
		inc = fabs(diff.y);
	step_x = diff.x / inc;
	step_y = diff.y / inc;
	diff = init_vect(start.x, start.y, start.z);
	while (i <= inc)
	{
		ft_put_pixel(mlx, diff.x, diff.y, 0X0000FF);
		diff.x += step_x;
		diff.y += step_y;
		i++;
	}
}

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
				ft_put_pixel(mlx, step_x, step_y, 0X00FF00);
			step_y++;
		}
		step_x++;
	}
}
/*first test : failed*/
void	ray_tracing(t_mlx *mlx, t_ray *r)
{
	t_vect	trace;
	double	max;
	double	step;

	step = 0.1;
	max = vect_lenght(r->direction) * 1000;
	while (step <= max)
	{
		trace.x = r->origin.x + step * r->direction.x;
		trace.y = r->origin.y + step * r->direction.y;
		ft_put_pixel(mlx, trace.x, trace.y, 0X00FF00);
		step += 0.1;
	}
}

int	ft_intersec_sp(t_sp *obj, t_ray *r, int *solution)
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
	printf("discr: %f\n", discriminant);
	if (discriminant < 0)
		return (EXIT_FAILURE);
	*solution = (- b / (2 * a)) - (sqrt(discriminant) / (2 * a));
	if (*solution < 0)
		*solution = (- b / (2 * a))+ (sqrt(discriminant) / (2 * a));
	return (EXIT_SUCCESS);
}

void	go_sphere(t_mlx *mlx, t_sp *obj)
{
	t_ray	r;
	int		racine;
	int		val;

	racine = 0;
	r.origin = init_vect(100, 100, 0);
	ft_put_pixel(mlx, r.origin.x, r.origin.y, 0XFFFFFF);
	r.direction = init_vect(obj->center.x, obj->center.y, obj->center.z);
	ft_put_pixel(mlx, obj->center.x, obj->center.y, 0X0000FF);
	dda_algo(mlx, r.origin, r.direction);
	val = ft_intersec_sp(obj, &r, &racine);
	if (val == EXIT_FAILURE)
		ft_printf("Pas d'intersection\n");
	else
		ft_printf("Find intersection !\n");
}

void	debug_scene(t_scene *scene)
{
	printf("=========== Ambient light ===============\n");
	ft_disp_content_a(scene->amlight);
	printf("=========== Camera ===============\n");
	ft_disp_content_c(scene->cam);
	printf("=========== Light ===============\n");
	ft_disp_content_l(scene->light);
}

int	main(int argc, char **argv)
{
	t_scene	*data;
	t_sp	*obj;

	data = get_struct();
	data->world = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_error_init(argc, argv) == EXIT_FAILURE
		|| check_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_scene(data, argv[1]);
	debug_scene(data);
	ft_debug(data->world);
	obj = (t_sp *)get_type(data->world, Sphere);
	if (obj != NULL)
	{
		draw_sphere(data->mlx, obj);
		go_sphere(data->mlx, obj);
	}
	// ray_tracing(data->mlx, origin);
	ft_launch(data);
	return (EXIT_SUCCESS);
}
