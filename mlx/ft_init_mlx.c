/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:27:53 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 11:00:07 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static void	ft_img_init(t_scene *scene, int x, int y)\
{
	t_mlx	*data;

	data = scene->mlx;
	data->img_ptr = mlx_new_image(data->mlx_ptr, x, y);
	if (data->img_ptr == NULL)
		ft_close_window(scene);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->byte_p_pixel,
			&data->size_line, &data->endian);
	if (data->img_addr == NULL)
		ft_close_window(scene);
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

void	ft_init_scene(t_scene *data, char *title)
{
	t_mlx	*tmp;

	tmp = malloc(sizeof(t_mlx));
	if (!tmp)
		return ;
	tmp->mlx_ptr = mlx_init();
	if (tmp->mlx_ptr == NULL)
		exit(1);
	ft_window_init(tmp, title);
	data->mlx = tmp;
	ft_img_init(data, WINDOW_X, WINDOW_Y);
	data->mlx = tmp;
}
