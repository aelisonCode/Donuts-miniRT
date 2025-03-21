/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:51:50 by mravelon          #+#    #+#             */
/*   Updated: 2025/03/19 11:14:43 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

void	put_error(char *res)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, res, ft_strlen(res));
}

int	check_rang(char *str, double min, double max)
{
	double	val;

	val = ft_atof(str);
	if (val < min || val > max)
	{
		put_error("Some value dont respect the rang!!!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_color(char *color)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(color, ',');
	if (tab_length(tmp) != 3)
	{
		put_error("Miss some argument to some color !!!\n");
		return (EXIT_FAILURE);
	}
	else
	{
		while (tmp[i])
		{
			if (check_rang(tmp[i], 0, 255) == EXIT_FAILURE)
			{
				ft_free_tab(tmp);
				return (EXIT_FAILURE);
			}
			i++;
		}
	}
	ft_free_tab(tmp);
	return (EXIT_SUCCESS);
}

int	check_vector(char *str)
{
	char	**tmp;

	tmp = ft_split(str, ',');
	if (tab_length(tmp) != 3)
	{
		put_error("Your vector must have 3 values(x, y, z)\n");
		ft_free_tab(tmp);
		return (EXIT_FAILURE);
	}
	ft_free_tab(tmp);
	return (EXIT_SUCCESS);
}

int	check_vector_rang(char *str, double min, double max)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(str, ',');
	if (tab_length(tmp) != 3)
	{
		put_error("Your vector must have 3 values(x, y, z)\n");
		ft_free_tab(tmp);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (tmp[i])
	{
		if (check_rang(tmp[i], min, max) == EXIT_FAILURE)
		{
			ft_free_tab(tmp);
			return (EXIT_FAILURE);
		}
		i++;
	}
	ft_free_tab(tmp);
	return (EXIT_SUCCESS);
}
