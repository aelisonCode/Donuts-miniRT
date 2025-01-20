/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:33:31 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 13:36:36 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_launch(t_mlx *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0,
		0);
	mlx_key_hook(data->mlx_window, ft_exec_input, data);
	mlx_hook(data->mlx_window, 17, 1L << 17, ft_close_window, data);
	mlx_loop(data->mlx_ptr);
}
