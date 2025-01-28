/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:43:45 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/28 14:07:15 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/struct.h"
#include <unistd.h>

void	*get_struct(void)
{
	static t_scene	res;

	return (&res);
}
