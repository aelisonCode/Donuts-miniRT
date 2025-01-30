/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:01:07 by aelison           #+#    #+#             */
/*   Updated: 2025/01/15 14:51:42 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/utils.h"

int	ft_error_init(int argc, char **argv)
{
	int	tmp;

	if (argc != 2)
	{
		ft_putendl_fd("Error:\nNot valid argument", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else
	{
		tmp = ft_strlen(argv[1]);
		if (tmp <= 3 || ft_count_char(argv[1], '.') != 1)
		{
			ft_putendl_fd("Error:\nNot valid file", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		tmp -= 3;
		if (ft_strncmp(argv[1] + tmp, ".rt", 4) != 0)
		{
			ft_putendl_fd("Error:\nNot valid extension", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
