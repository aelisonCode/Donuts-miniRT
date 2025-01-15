/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:09 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 09:26:06 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

int	for_sphere(char **all)
{
	int	i;
	int	cont;

	i = 1;
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 4)
		return (EXIT_FAILURE);
	return (2);
}

int	for_plane(char **all)
{
	int	i;
	int	cont;

	i = 1;
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 4)
		return (EXIT_FAILURE);
	return (2);
}

int	for_cylender(char **all)
{
	int	i;
	int	cont;

	i = 1;
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 6)
		return (EXIT_FAILURE);
	return (2);
}
