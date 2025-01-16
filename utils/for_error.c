/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:52:35 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 17:26:09 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

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
			printf("error : don't respect the rang \n");
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
		printf("error : missing some arg \n");
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
	ft_free_tab(split);
	if (i != lg)
	{
		printf("error : missing some arg lvl 1\n");
		return (1);
	}
	return (0);
}
