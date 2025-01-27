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
	t_scene			*data;
	t_sp			*obj;

	data = get_struct();
	data->world = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_error_init(argc, argv) == EXIT_FAILURE
		|| check_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_scene(data, 1.0, argv[1]);
	obj = (t_sp *)get_type(data->world, Sphere);
	if (obj != NULL)
	{
		send_ray(data->mlx, data->p, data->cam, obj);
	}
	ft_launch(data);
	return (EXIT_SUCCESS);
}
