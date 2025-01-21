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

t_vect	ft_normalize(double x, double y, double z)
{
	t_vect	res;
	double	norm;

	norm = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	res.x /= norm;
	res.y /= norm;
	res.z /= norm;
	return (res);
}

t_vect	ft_ray_move(t_vect origine, t_vect dir)
{
	t_vect	res;

	res.x = dir.x - origine.x;
	res.y = dir.y - origine.y;
	res.z = dir.z - origine.z;
	return (res);
}

void	test(t_maps *head, t_mlx *mlx)
{
	t_vect	origine;
	t_vect	dir;
	t_vect	norm;
	t_vect	move;
	int		i;

	head++;
	origine.x = 100;
	origine.y = 50;
	origine.z = 0;
	dir.x = 500;
	dir.y = 500;
	dir.z = 0;
	ft_put_pixel(mlx, round(origine.x), round(origine.y), 0XFFFFFF);
	ft_put_pixel(mlx, round(dir.x), round(dir.y), 0X00FF00);
	norm = ft_normalize(move.x, move.y, move.z);
	i = 0;
	while (move.x != dir.x)
	{
		ft_printf("enter %d\n", i);
		move = ft_ray_move(norm, dir);
		norm = ft_normalize(move.x, move.y, move.z);
		ft_put_pixel(mlx, round(norm.x), round(norm.y), 0XFF0000);
		i++;
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
	test(data->world, data->mlx);
	// ft_put_pixel(data->mlx, WINDOW_X / 2, WINDOW_Y / 2, 0XFF0000);
	ft_launch(data);
	return (EXIT_SUCCESS);
}
