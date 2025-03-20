/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:57:36 by mravelon          #+#    #+#             */
/*   Updated: 2025/03/19 11:20:33 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

int	check_value(char *str)
{
	if (str && ft_atof(str) > 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	verify_sphere(char **str)
{
	if (check_vector(str[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_value(str[2]) == EXIT_FAILURE)
	{
		put_error("The diameter of the sphere must be > 0 !!!\n");
		return (EXIT_FAILURE);
	}
	if (check_color(str[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	verify_plane(char **str)
{
	if (check_vector(str[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_vector_rang(str[2], -1, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_normal(str[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_color(str[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	verify_cylinder(char **str)
{
	if (check_vector(str[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_vector_rang(str[2], -1, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_normal(str[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_value(str[3]) == EXIT_FAILURE)
	{
		put_error("The diameter of the cylinder must be > 0 !!!\n");
		return (EXIT_FAILURE);
	}
	if (check_value(str[4]) == EXIT_FAILURE)
	{
		put_error("The height of the height of the cylinder must be > 0 !!!\n");
		return (EXIT_FAILURE);
	}
	if (check_color(str[5]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
