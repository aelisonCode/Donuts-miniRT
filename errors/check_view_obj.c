/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:16:23 by aelison           #+#    #+#             */
/*   Updated: 2025/01/15 08:40:39 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

int	for_ambient_l(char **all, int *t)
{
	int	i;
	int	cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 3)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}

int	for_camera(char **all, int *t)
{
	int	i;
	int	cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 4)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}

int	for_light(char **all, int *t)
{
	int	i;
	int	cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 4)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}
