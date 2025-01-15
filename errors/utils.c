/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:12:19 by aelison           #+#    #+#             */
/*   Updated: 2025/01/15 08:13:05 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

static int	valid_format_aux(char *str, int *i)
{
	while (str[*i] && ft_isdigit(str[*i]) != 0)
		(*i)++;
	if (str[*i] == '.' || str[*i] == ',')
	{
		if (ft_isdigit(str[(*i) + 1]) == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	is_valid_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]) == 0)
			return (EXIT_FAILURE);
		else if (ft_isdigit(str[i]) != 0)
		{
			if (valid_format_aux(str, &i) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (str[i] != '-' && str[i] != '+')
			return (EXIT_FAILURE);
		if (str[i])
			i++;
	}
	return (EXIT_SUCCESS);
}
