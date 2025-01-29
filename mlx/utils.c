/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:04:52 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 07:06:52 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	ft_is_in_window(int x, int y)
{
	if (x >= 0 && x <= WINDOW_X)
	{
		if (y >= 0 && y <= WINDOW_Y)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	ft_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*tmp;

	if (ft_is_in_window(x, y) == EXIT_SUCCESS)
	{
		tmp = data->img_addr + (y * data->size_line + x * (data->byte_p_pixel
					/ 8));
		*(unsigned int *)tmp = color;
	}
}

void	gen_new_image(t_scene *scene)
{
	t_mlx	*data;

	data = scene->mlx;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_X, WINDOW_Y);
	if (data->img_ptr == NULL)
		ft_close_window(scene);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->byte_p_pixel,
			&data->size_line, &data->endian);
	if (data->img_addr == NULL)
		ft_close_window(scene);
}
