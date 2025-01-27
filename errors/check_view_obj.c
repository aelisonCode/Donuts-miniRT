/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:16:23 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 10:22:35 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/mini_rt.h"
#include "../header/struct.h"

int	for_ambient_l(char **all, int *t)
{
	int		i;
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
	s->amlight = ambient_l(all);
	(*t)++;
	return (1);
}

int	for_camera(char **all, int *t)
{
	int		i;
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
	if (i != 4)
		return (0);
	if (for_camera_param(all) == 1)
		return (0);
	(*t)++;
	s = get_struct();
	s->cam = camera(all);
	return (2);
}

int	for_light(char **all, int *t)
{
	int		i;
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
	if (i != 4)
		return (0);
	if (for_light_param(all) == 1)
		return (0);
	(*t)++;
	s = get_struct();
	s->light = light(all);
	return (3);
}
