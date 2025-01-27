/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:12:19 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 10:28:54 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/utils.h"

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

int	limit(char **str, double max, double min)
{
	int		i;
	double	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		ft_replace_str(str[i], "\n", '\0');
		x = ft_atof(str[i]);
		if (x >= min && x <= max)
			i++;
		else
		{
			ft_putstr_fd("error : don't respect the rang \n", STDERR_FILENO);
			return (1);
		}
	}
	return (0);
}

int	check_vector_l(char *str, double max, double min, long lg)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ',');
	while (split[i])
		i++;
	if (i != lg)
	{
		ft_putstr_fd("error : missing some arg \n", STDERR_FILENO);
		ft_free_tab(split);
		return (1);
	}
	i = 0;
	i = limit(split, max, min);
	ft_free_tab(split);
	return (i);
}

int	check_vector(char *str, long lg)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ',');
	while (split[i])
		i++;
	if (i != lg)
	{
		ft_putstr_fd("error : missing some arg lvl 1\n", STDERR_FILENO);
		ft_free_tab(split);
		return (1);
	}
	ft_free_tab(split);
	return (0);
}
