/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:09 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 14:50:24 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/mini_rt.h"

int	for_sphere(char **all)
{
	int		i;
	t_scene	*s;

	i = 1;
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	if (for_sphere_param(all) == 1)
		return (0);
	s = get_struct();
	add_maps(&s->world, create_map(Sphere, sphere(all)));
	return (4);
}

int	for_plane(char **all)
{
	int		i;
	t_scene	*s;

	i = 1;
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	if (for_plane_param(all) == 1)
		return (0);
	s = get_struct();
	add_maps(&s->world, create_map(Plane, plane(all)));
	return (5);
}

int	for_cylender(char **all)
{
	int		i;
	t_scene	*s;

	i = 1;
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (0);
		i++;
	}
	if (i != 6)
		return (0);
	if (for_cylender_param(all) == 1)
		return (0);
	s = get_struct();
	add_maps(&s->world, create_map(Cylinder, cylender(all)));
	return (6);
}
