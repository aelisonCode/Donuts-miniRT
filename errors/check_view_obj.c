/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:16:23 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 10:39:28 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/struct.h"
#include "../header/mini_rt.h"

int	for_ambient_l(char **all, int *t)
{
	int	i;
	t_scene	*s;

	i = 1;
	if (*t != 0)
		return (0);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	if (for_ambient_param(all) == 1)
		return (0);
	s = get_struct();
	(*t)++;
	add_maps(&s->world, create_map(Ambient_l, ambient_l(all)));
	return (1);
}

int	for_camera(char **all, int *t)
{
	int	i;

	i = 1;
	if (*t != 0)
		return (0);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	if (for_camera_param(all) == 1)
		return (0);
	(*t)++;
	return (2);
}

int	for_light(char **all, int *t)
{
	int	i;

	i = 1;
	if (*t != 0)
		return (0);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	if (for_light_param(all) == 1)
		return (0);
	(*t)++;
	return (3);
}
