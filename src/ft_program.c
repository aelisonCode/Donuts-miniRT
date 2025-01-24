/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:51 by aelison           #+#    #+#             */
/*   Updated: 2025/01/23 09:23:27 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"
#include <stdio.h>

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

void	debug_scene(t_scene *scene)
{
	printf("=========== Ambient light ===============\n");
	ft_disp_content_a(scene->amlight);
	printf("=========== Camera ===============\n");
	ft_disp_content_c(scene->cam);
	printf("=========== Light ===============\n");
	ft_disp_content_l(scene->light);
}

void	debug_projection(t_projection p)
{
	printf("height = %f\n", p.height);
	printf("width = %f\n", p.width);

	printf("top_left x = %f\n", p.top_left.x);
	printf("top_left y = %f\n", p.top_left.y);
	printf("top_left z = %f\n", p.top_left.z);

	printf("height dir x = %f\n", p.height_dir.x);
	printf("height dir y = %f\n", p.height_dir.y);
	printf("height dir z = %f\n", p.height_dir.z);

	printf("width dir x = %f\n", p.width_dir.x);
	printf("width dir y = %f\n", p.width_dir.y);
	printf("width dir z = %f\n", p.width_dir.z);
}

int	main(int argc, char **argv)
{
	t_scene	*data;
	t_sp	*obj;
	t_projection p;

	data = get_struct();
	data->world = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_error_init(argc, argv) == EXIT_FAILURE
		|| check_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_scene(data, argv[1]);
	p = init_pjct(data->cam, 1.0);
	printf("ratio = %f\n", data->cam->ratio);
	debug_projection(p);
	// debug_scene(data);
	// ft_debug(data->world);
	obj = (t_sp *)get_type(data->world, Sphere);
	if (obj != NULL)
	{
		// draw_sphere(data->mlx, obj);
		// go_sphere(data->mlx, obj);
		send_ray(data->mlx, p, data->cam, obj);
	}
	ft_launch(data);
	return (EXIT_SUCCESS);
}
