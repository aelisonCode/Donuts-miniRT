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

void	ft_draw_sp(t_mlx *mlx)
{
	t_vect	originne;
	t_vect	draw;
	t_vect	pixel;
	double	radius;
	double	step_x;
	double	step_y;
	double	diameter;
	double	ecart;

	diameter = 200;
	radius = diameter / 2;
	ecart = diameter * 2;
	originne.x = WINDOW_X / 2;
	originne.y = WINDOW_Y / 2;
	originne.z = 0;
	draw.x = 0;
	draw.y = 0;
	draw.z = 0;
	step_x = M_PI / ecart;
	step_y = 2 * M_PI / ecart;
	while (draw.x <= M_PI)
	{
		draw.y = 0;
		while (draw.y <= 2 * M_PI)
		{
			pixel.x = originne.x + radius * sin(draw.x) * cos(draw.y);
			pixel.y = originne.y + radius * sin(draw.x) * sin(draw.y);
			ft_put_pixel(mlx, (pixel.x), (pixel.y), 0XFF0000);
			draw.y += step_y;
		}
		draw.x += step_x;
	}
}

void	debug_scene(t_scene	*scene)
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
	ft_draw_sp(data->mlx);
	// test(data->world, data->mlx);
	ft_launch(data);
	return (EXIT_SUCCESS);
}
