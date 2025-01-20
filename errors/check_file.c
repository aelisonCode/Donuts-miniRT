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

static int	parse_object(char *str)
{
	int			result;
	char		**split;
	static int	exist[6];

	split = ft_split(str, ' ');
	result = EXIT_FAILURE;
	if (!split)
		return (result);
	if (split[0][0] == '\n')
		result = EXIT_SUCCESS;
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
	static int	obj_create;
	int			val;

	val = parse_object(tmp);
	if (val == 2)
		obj_create++;
	else if (val == EXIT_FAILURE)
	{
		ft_printf("error: file content: line: %d\n", line);
		*res = -1;
	}
	if (*res == -1)
		return (-1);
	return (obj_create);
}

static int	file_content(int fd)
{
	int		i;
	int		obj;
	int		error;
	char	*tmp;

	tmp = "\0";
	obj = 0;
	i = 0;
	error = 0;
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

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error: file: can't open %s\n", str);
		return (EXIT_FAILURE);
	}
	result = file_content(fd);
	if (result == 0)
		ft_printf("error: parse: failed to create obj\n");
	close(fd);
	return (result);
}
