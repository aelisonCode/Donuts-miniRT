/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:30:47 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 17:16:51 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

double	revers(long p)
{
	double	i;
	double	nbr;

	i = 0;
	nbr = 10;
	while (i <= p)
	{
		nbr = nbr * (0.1);
		i++;
	}
	return (nbr);
}

void	init(double *nbr, long *i, long *j, long *signe)
{
	*nbr = 0;
	*i = 0;
	*j = 1;
	*signe = 1;
}

void	for_the_rest(long *i, long *j, double *nbr, char *str)
{
	(*i)++;
	while (str[*i])
	{
		*nbr = *nbr + (str[*i] - '0' ) * revers(*j);
		(*i)++;
		(*j)++;
	}
}

double	ft_atof(char *str)
{
	double	nbr;
	long	i;
	long	j;
	long	signe;

	init(&nbr, &i, &j, &signe);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		for_the_rest(&i, &j, &nbr, str);
	return (nbr * signe);
}
