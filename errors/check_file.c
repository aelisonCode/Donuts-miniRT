/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:55:29 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 17:25:36 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/utils.h"
#include <unistd.h>

static int	get_required_obj(int value)
{
	static int	required[4];
	int			i;

	if (value != 0 && value < 4)
		required[value] = required[value] + 1;
	i = 1;
	while (i < 4)
	{
		if (required[i] != 1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	parse_object(char *str)
{
	int			result;
	char		**split;
	static int	exist[6];

	split = ft_split(str, ' ');
	result = 0;
	if (!split)
		return (result);
	if (split[0][0] == '\n')
		result = 7;
	else if (ft_strncmp(split[0], "A", 2) == EXIT_SUCCESS)
		result = for_ambient_l(split, &exist[0]);
	else if (ft_strncmp(split[0], "C", 2) == EXIT_SUCCESS)
		result = for_camera(split, &exist[1]);
	else if (ft_strncmp(split[0], "L", 2) == EXIT_SUCCESS)
		result = (for_light(split, &exist[2]));
	else if (ft_strncmp(split[0], "sp", 3) == EXIT_SUCCESS)
		result = for_sphere(split);
	else if (ft_strncmp(split[0], "pl", 3) == EXIT_SUCCESS)
		result = for_plane(split);
	else if (ft_strncmp(split[0], "cy", 3) == EXIT_SUCCESS)
		result = for_cylender(split);
	ft_free_tab(split);
	return (result);
}

static int	create_object(char *tmp, int line, int *res)
{
	int	valid_ok;
	int	val;

	val = parse_object(tmp);
	valid_ok = get_required_obj(val);
	if (val == 0)
	{
		ft_putstr_fd("Error: wrong format on line ", STDERR_FILENO);
		ft_putnbr_fd(line, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		*res = EXIT_FAILURE;
		return (*res);
	}
	if (valid_ok == EXIT_FAILURE)
		*res = EXIT_FAILURE;
	else if (valid_ok == EXIT_SUCCESS)
		*res = EXIT_SUCCESS;
	if (*res == EXIT_FAILURE)
		return (*res);
	return (EXIT_SUCCESS);
}

static int	file_content(int fd)
{
	int		i;
	int		obj;
	int		error;
	char	*tmp;

	tmp = "\0";
	obj = EXIT_FAILURE;
	i = 0;
	error = EXIT_FAILURE;
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			i++;
			ft_replace_str(tmp, "\t\a\b\v\f\r", ' ');
			obj = create_object(tmp, i, &error);
			free(tmp);
		}
	}
	return (obj);
}

int	check_file(char *str)
{
	int	result;
	int	fd;

	result = EXIT_SUCCESS;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: file: can't open ", STDERR_FILENO);
		ft_putendl_fd(str, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	result = file_content(fd);
	if (result == EXIT_FAILURE)
		ft_putstr_fd("Error: parse: failed to create obj\n", STDERR_FILENO);
	close(fd);
	return (result);
}
