/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filltab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:11:30 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/14 15:14:04 by mravelon         ###   ########.fr       */
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
