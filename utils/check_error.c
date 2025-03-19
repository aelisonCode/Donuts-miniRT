/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:37:47 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/27 17:56:12 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"
#include "../header/errors.h"
#include "../header/vector.h"

static int	valid_format_aux(char *str, int *i)
{
	while (str[*i] && ft_isdigit(str[*i]) != 0)
		(*i)++;
	if (str[*i] == '.' || str[*i] == ',')
	{
		if (str[*i] == ',' && (str[(*i) + 1] == '+' || str[(*i) + 1] == '-'))
			return (EXIT_SUCCESS);
		if (ft_isdigit(str[(*i) + 1]) == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	is_valid_format(char *str)
{
	int	i;
	int	status;

	i = 0;
	status = EXIT_SUCCESS;
	while (str[i] && status == EXIT_SUCCESS)
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]) == 0)
			status = EXIT_FAILURE;
		else if (ft_isdigit(str[i]) != 0)
			status = valid_format_aux(str, &i);
		else if (str[i] != '-' && str[i] != '+')
			status = EXIT_FAILURE;
		if (str[i])
			i++;
	}
	if (status == EXIT_FAILURE)
		put_error("Invalide argument !!! DIGIT ONLY PLS!");
	return (status);
}

int	valid_format(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (is_valid_format(str[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_normalize(t_vect x)
{
	if (vect_length(x) != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
