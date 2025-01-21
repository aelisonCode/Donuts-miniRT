/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:02:49 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/14 15:04:00 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/struct.h"
#include <stdlib.h>

void	ft_free_tab(char **ptr)
{
	int	i;

	if (!ptr || *ptr == NULL)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	ft_free_map(t_maps **head)
{
	t_maps	*tmp;

	while (*head)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp->struct_obj);
		free(tmp);
	}
	*head = NULL;
}
