/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:27:53 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 07:29:17 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static void	ft_img_init(t_mlx *data, int x, int y)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, x, y);
	if (data->img_ptr == NULL)
		ft_close_window(data);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->byte_p_pixel,
			&data->size_line, &data->endian);
	if (data->img_addr == NULL)
		ft_close_window(data);
}

static void	ft_window_init(t_mlx *data, char *title)
{
	data->mlx_window = mlx_new_window(data->mlx_ptr, WINDOW_X, WINDOW_Y, title);
	if (data->mlx_window == NULL)
	{
		ft_putendl_fd("error: mlx_new_window fail", STDERR_FILENO);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
}

void	ft_init_mlx(t_mlx *data, char *title)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	ft_window_init(data, title);
	ft_img_init(data, WINDOW_X, WINDOW_Y);
}
