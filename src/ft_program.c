/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:51 by aelison           #+#    #+#             */
/*   Updated: 2025/01/14 15:29:18 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc == 1)
		ft_init_mlx(&data, "test");
	else
	{
		check_file(argv[1]);
		ft_init_mlx(&data, argv[1]);
	}
	mlx_key_hook(data.mlx_window, ft_exec_input, &data);
	mlx_hook(data.mlx_window, 17, 1L << 17, ft_close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
