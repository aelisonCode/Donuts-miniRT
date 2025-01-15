/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_view_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:26:55 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 17:28:57 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/utils.h"

int	for_ambient_param(char **all)
{
	char	**split;
	int		i;

	i = 0;
	if (check_vector_l(all[1], 1.0, 0.0, 1) == 1)
		return (1);
	if (check_vector_l(all[2], 255, 0, 3) == 1)
		i = 1;
	return (i);
}

int	for_camera_param(char **all)
{
	if (check_vector(all[1], 3) == 1)
		return (1);
	if (check_vector_l(all[2], 1, 0.0, 3) == 1)
		return (1);
	if (check_vector_l(all[3], 180, 0, 1))
		return (1);
	return (0);
}

int	for_light_param(char **all)
{
	if (check_vector(all[1], 3) == 1)
		return (1);
	if (check_vector_l(all[2], 1.0, 0.0, 1) == 1)
		return (1);
	if (check_vector_l(all[3], 255, 0, 3) == 1)
		return (1);
	return (0);
}
