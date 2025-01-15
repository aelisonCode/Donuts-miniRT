/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:51 by aelison           #+#    #+#             */
/*   Updated: 2025/01/15 08:23:50 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_error_init(argc, argv) == EXIT_FAILURE
		|| check_file(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_mlx(&data, argv[1]);
	mlx_key_hook(data.mlx_window, ft_exec_input, &data);
	mlx_hook(data.mlx_window, 17, 1L << 17, ft_close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
