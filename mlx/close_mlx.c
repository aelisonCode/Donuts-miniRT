/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:23:21 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 11:09:05 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_free_mlx(t_scene *data)
{
	t_mlx	*tmp;

	tmp = data->mlx;
	free(tmp->mlx_ptr);
	free(tmp);
	free(data->amlight);
	free(data->cam);
	free(data->light);
}

int	ft_close_window(t_scene *scene)
{
	t_mlx	*data;

	data = scene->mlx;
	if (data)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		ft_free_map(&scene->world);
		ft_free_mlx(scene);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
