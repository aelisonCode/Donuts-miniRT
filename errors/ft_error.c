/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:57:26 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/26 13:58:49 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	missing_primary_aux(t_scene *data, int *i)
{
	if (!data->cam)
	{
		if (*i != 0)
			write(STDERR_FILENO, " and ", ft_strlen(" and "));
		write(STDERR_FILENO, "camera", ft_strlen("camera"));
		(*i)++;
	}
	if (!data->amlight)
	{
		if (*i != 0)
			write(STDERR_FILENO, " and ", ft_strlen(" and "));
		write(STDERR_FILENO, "ambient light", ft_strlen("ambient ligtht"));
		(*i)++;
	}
}

void	missing_primary(t_scene *data)
{
	int	i;

	i = 0;
	if (!data->cam && !data->amlight && !data->light)
		put_error("Missing all primary !!!\n");
	else
	{
		write(STDERR_FILENO, "Missing ", ft_strlen("Missing "));
		missing_primary_aux(data, &i);
		if (!data->light)
		{
			if (i != 0)
				write(STDERR_FILENO, " and ", ft_strlen(" and "));
			write(STDERR_FILENO, "light", ft_strlen("light"));
			i++;
		}
		write(STDERR_FILENO, " !!!\n", ft_strlen(" !!!\n"));
	}
}

int	ft_error(int fd, char **argv, t_scene *data)
{
	int	empty;
	int	status;

	empty = 1;
	status = EXIT_SUCCESS;
	if (check_name_file(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_void_file(fd, data, &empty, &status) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (data->light == NULL || data->amlight == NULL || data->cam == NULL)
	{
		missing_primary(data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_normal(char *str)
{
	t_vect	v;
	char	**tmp;

	tmp = ft_split(str, ',');
	v = init_vect(ft_atof(tmp[0]), ft_atof(tmp[1]), ft_atof(tmp[2]));
	ft_free_tab(tmp);
	vect_length(v);
	if (vect_length(v) != 1)
	{
		put_error("A Vector is not normalized in you're map\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
