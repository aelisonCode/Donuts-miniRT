/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:01:07 by aelison           #+#    #+#             */
/*   Updated: 2025/01/14 14:32:42 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

void	ft_error_init(int argc, char **argv)
{
	int	tmp;

	if (argc != 2)
	{
		ft_putendl_fd("error: not valid argument", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	else
	{
		tmp = ft_strlen(argv[1]);
		if (tmp <= 3)
		{
			ft_putendl_fd("error: not valid file", STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
		tmp -= 4;
		if (ft_strncmp(argv[1] + tmp, ".rt", 4) != 0)
		{
			ft_putendl_fd("error: not valid extension", STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
	}
}
