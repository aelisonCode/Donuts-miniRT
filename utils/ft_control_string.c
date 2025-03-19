/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:29:54 by aelison           #+#    #+#             */
/*   Updated: 2025/01/15 08:36:18 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

void	ft_filltab(int *tab, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tab[i] = val;
		i++;
	}
}

void	ft_replace_str(char *to_change, char *set, char val)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!to_change || !set)
		return ;
	while (to_change[i])
	{
		tmp = ft_strchr(set, to_change[i]);
		if (tmp != NULL)
			to_change[i] = val;
		i++;
	}
}

long	ft_count_char(char *target, char to_count)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	if (!target)
		return (result);
	while (target[i])
	{
		if (target[i] == to_count)
			result++;
		i++;
	}
	return (result);
}
