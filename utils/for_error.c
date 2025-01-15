/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:52:35 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 15:17:10 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

int limit(char ***str, double max, double min)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		printf("str = %s\n", *str[i]);
		if (ft_atof((*str)[i]) > max || ft_atof((*str)[i]) < min)
		{
			printf("nbr = %f\n", ft_atof((*str)[i]));
			printf("error : don't respect the rang \n");
			return (1);
		}
		i++;
	}
	return (0);
}

int check_vector_l(char *str, double max, double min, long lg)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(str, ',');
	while (split[i])
	{
		printf("split[%d] = %s\n", i, split[i]);
		i++;
	}
	ft_free_tab(split);
	if (i != lg)
	{
		printf("error : missing some arg \n");
		return (1);
	}
	i = 0;
	i = limit(&split, max, min);
	return (i);
}

int check_vector(char *str, long lg)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(str, ',');
	while (str[i])
		i++;
	ft_free_tab(split);
	if (i != lg)
		return (1);
	return (0);
}
