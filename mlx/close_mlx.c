/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:23:21 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 07:24:38 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_free_mlx(t_mlx *data)
{
	free(data->mlx_ptr);
}

int	ft_close_window(t_mlx *data)
{
	if (data)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		ft_free_mlx(data);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
