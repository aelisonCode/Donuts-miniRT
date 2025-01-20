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
	t_mlx	tmp;

	tmp = *data;
	tmp.img_ptr = mlx_new_image(tmp.mlx_ptr, x, y);
	tmp.img_addr = mlx_get_data_addr(&(tmp).img_addr, &(tmp).byte_p_pixel,
			&(tmp).syze_line, &(tmp).endian);
	*data = tmp;
}

static void	ft_window_init(t_mlx *data, char *title)
{
	mlx_get_screen_size(data->mlx_ptr, &data->w_sizex, &data->w_sizey);
	data->mlx_window = mlx_new_window(data->mlx_ptr, data->w_sizex,
			data->w_sizey, title);
	if (data->mlx_window == NULL)
	{
		ft_putendl_fd("error: mlx_window fail", STDERR_FILENO);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
}

void	ft_init_mlx(t_mlx *data, char *title)
{
	data->mlx_ptr = mlx_init();
	ft_window_init(data, title);
	ft_img_init(data, data->w_sizex, data->w_sizey);
}
