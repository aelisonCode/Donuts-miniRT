/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:51 by aelison           #+#    #+#             */
/*   Updated: 2025/01/23 09:23:27 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	main(int argc, char **argv)
{
	t_scene	data;

	data.world = NULL;
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_error_init(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_file(&data, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_scene(&data, 1.0, argv[1]);
	ft_launch(&data);
	return (EXIT_SUCCESS);
}
