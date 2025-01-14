/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:30:29 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/14 14:36:13 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

void	ft_replace_str(char *to_change, char *set, char val)
{
	int 	i;
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
