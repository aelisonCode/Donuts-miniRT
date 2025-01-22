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

void	test(t_maps *head, t_mlx *mlx)
{
	t_vect	origine;
	t_vect	dir;
	t_vect	norm;
	t_vect	move;
	int		i;

	head++;
	origine = init_vect(100, 50, 0);
	dir = init_vect(500, 500, 0);
	move = init_vect(0, 0, 0);
	ft_put_pixel(mlx, round(origine.x), round(origine.y), 0XFFFFFF);
	ft_put_pixel(mlx, round(dir.x), round(dir.y), 0X00FF00);
	norm = ft_normalize(move);
	i = 0;
	while (move.x != dir.x)
	{
		ft_printf("enter %d\n", i);
		move = substraction(norm, dir);
		norm = ft_normalize(move);
		ft_put_pixel(mlx, round(norm.x), round(norm.y), 0XFF0000);
		i++;
	}
}

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

int	main(int argc, char **argv)
{
	t_scene	*data;

	data = get_struct();
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_error_init(argc, argv) == EXIT_FAILURE
		|| check_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_debug(data->world);
	ft_init_scene(data, argv[1]);
	ft_draw_sp(data->mlx);
	// test(data->world, data->mlx);
	ft_launch(data);
	return (EXIT_SUCCESS);
}
