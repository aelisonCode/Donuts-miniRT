/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:13:20 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/21 11:26:33 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/utils.h"

int	for_sphere_param(char **all)
{
	if (check_vector(all[1], 3) == 1)
		return (1);
	if (check_vector(all[2], 1) == 1)
		return (1);
	if (check_vector_l(all[3], 255, 0, 3) == 1)
		return (1);
	return (0);
}

int	for_plane_param(char **all)
{
	if (check_vector(all[1], 3) == 1)
		return (1);
	if (check_vector_l(all[2], 1, -1, 3) == 1)
		return (1);
	if (check_vector_l(all[3], 255, 0, 3) == 1)
		return (1);
	return (0);
}

int	for_cylinder_param(char **all)
{
	if (check_vector(all[1], 3) == 1)
		return (1);
	if (check_vector_l(all[2], 1, -1, 3) == 1)
		return (1);
	if (check_vector(all[3], 1) == 1)
		return (1);
	if (check_vector(all[4], 1) == 1)
		return (1);
	if (check_vector_l(all[5], 255, 0, 3) == 1)
		return (1);
	return (0);
}
