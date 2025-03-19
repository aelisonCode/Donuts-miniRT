/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:31:14 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/24 14:12:33 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

int	tab_length(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_strcmp(char *one, char *two)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!one || !two)
		return (-1);
	while (one[i] && two[i])
	{
		res = one[i] - two[i];
		if (res == 0)
			i++;
		else
			return (res);
	}
	return (one[i] - two[i]);
}
