/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:27:53 by aelison           #+#    #+#             */
/*   Updated: 2024/12/17 09:07:19 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_init_mlx(t_mlx *data, char *title)
{
	data->mlx_ptr = mlx_init();
	mlx_get_screen_size(data->mlx_ptr, &data->w_sizex, &data->w_sizey);
	data->mlx_window = mlx_new_window(data->mlx_ptr,
			data->w_sizex, data->w_sizey, title);
	if (data->mlx_window == NULL)
	{
		ft_putendl_fd("error: mlx_window fail", STDERR_FILENO);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		exit (EXIT_FAILURE);
	}
}

int	ft_close_window(t_mlx *data)
{
	if (data)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/*	Si appuie sur echappe quitte le programme	*/
int	ft_exec_input(int keycode, t_mlx *data)
{
	int	result;

	result = EXIT_FAILURE;
	if (data)
	{
		if (keycode == 65307)
			result = ft_close_window(data);
	}
	return (result);
}
