/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:01:43 by aelison           #+#    #+#             */
/*   Updated: 2025/01/22 13:05:40 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/struct.h"
#include <unistd.h>

void	*get_type(t_maps *obj, t_obj type)
{
	if (!obj)
		return (NULL);
	while (obj)
	{
		if (obj->type == type)
			return (obj->struct_obj);
		obj = obj->next;
	}
	return (NULL);
}
