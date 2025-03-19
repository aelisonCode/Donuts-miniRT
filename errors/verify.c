/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:49:33 by mravelon          #+#    #+#             */
/*   Updated: 2025/03/19 11:11:55 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

int	verify_ambient(char **str)
{
	if (check_rang(str[1], 0, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_color(str[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	verify_camera(char **str)
{
	if (check_vector(str[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_vector_rang(str[2], -1, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_zero(str[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_rang(str[3], 0.0, 180.0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	verify_light(char **str)
{
	if (check_vector(str[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_rang(str[2], -1, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_color(str[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
