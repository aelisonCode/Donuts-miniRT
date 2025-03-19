/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:18:31 by mravelon          #+#    #+#             */
/*   Updated: 2025/03/04 13:42:52 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"
#include "../header/utils.h"

int	for_sphere(char **str, t_scene *data)
{
	int	res;

	res = 0;
	if (valid_format(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (tab_length(str) != 4)
	{
		put_error("invalid number of argument for sphere!!!\n");
		return (EXIT_FAILURE);
	}
	res = verify_sphere(str);
	if (res != EXIT_FAILURE)
		add_maps(&data->world, create_map(Sphere, sphere(str)));
	return (res);
}

int	for_plane(char **str, t_scene *data)
{
	int	res;

	res = 0;
	if (valid_format(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (tab_length(str) != 4)
	{
		put_error("invalid number of argument for plane!!!\n");
		return (EXIT_FAILURE);
	}
	res = verify_plane(str);
	if (res != EXIT_FAILURE)
		add_maps(&data->world, create_map(Plane, plane(str)));
	return (res);
}

int	for_cylinder(char **str, t_scene *data)
{
	int	res;

	res = 0;
	if (valid_format(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (tab_length(str) != 6)
	{
		put_error("invalid number of argument for cylinder!!!\n");
		return (EXIT_FAILURE);
	}
	res = verify_cylinder(str);
	if (res != EXIT_FAILURE)
		add_maps(&data->world, create_map(Cylinder, cylinder(str)));
	return (res);
}
