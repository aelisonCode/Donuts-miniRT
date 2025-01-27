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

int	main(int argc, char **argv)
{
	t_scene	*data;
	t_maps	*tmp;

	data = get_struct();
	data->world = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_error_init(argc, argv) == EXIT_FAILURE
		|| check_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_scene(data, 1.0, argv[1]);
	tmp = data->world;
	while (tmp)
	{
		send_ray(data, tmp);
		tmp = tmp->next;
	}
	ft_launch(data);
	return (EXIT_SUCCESS);
}
