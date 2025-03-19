/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_prime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:00:44 by mravelon          #+#    #+#             */
/*   Updated: 2025/03/04 16:06:36 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/mini_rt.h"

int	for_ambient_l(char **str, t_scene *data)
{
	static int	i;
	int			res;

	i++;
	res = 0;
	if (valid_format(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (i != 1)
	{
		put_error("Your map should have only one ambient light !\n");
		return (EXIT_FAILURE);
	}
	if (tab_length(str) != 3)
	{
		put_error("invalid number of argument for ambient light!!!\n");
		return (EXIT_FAILURE);
	}
	res = verify_ambient(str);
	if (res != EXIT_FAILURE)
		data->amlight = ambient_l(str);
	return (res);
}

int	for_camera(char **str, t_scene *data)
{
	static int	i;
	int			res;

	i++;
	res = 0;
	if (valid_format(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (i != 1)
	{
		put_error("Your map should have only one camera !\n");
		return (EXIT_FAILURE);
	}
	if (tab_length(str) != 4)
	{
		put_error("invalid number of argument for camera!!!\n");
		return (EXIT_FAILURE);
	}
	res = verify_camera(str);
	if (res != EXIT_FAILURE)
		data->cam = camera(str);
	return (res);
}

int	for_ligth(char **str, t_scene *data)
{
	static int	i;
	int			res;

	i++;
	res = 0;
	if (valid_format(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (i != 1)
	{
		put_error("Your map should have only one light !\n");
		return (EXIT_FAILURE);
	}
	if (tab_length(str) != 4)
	{
		put_error("invalid number of argument for ligth!!!\n");
		return (EXIT_FAILURE);
	}
	res = verify_light(str);
	if (res != EXIT_FAILURE)
		data->light = light(str);
	return (res);
}
