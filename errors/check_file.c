/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:55:29 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 09:04:17 by aelison          ###   ########.fr       */
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

static int	file_content(int fd)
{
	int		i;
	int		result;
	char	*tmp;

	tmp = "\0";
	result = EXIT_SUCCESS;
	i = 0;
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			i++;
			ft_replace_str(tmp, "\t\a\b\v\f\r", ' ');
			if (parse_object(tmp) == EXIT_FAILURE)
			{
				ft_printf("error: file content: line: %d\n", i);
				result = EXIT_FAILURE;
			}
			free(tmp);
		}
	}
	return (result);
}

int	check_file(char *str)
{
	int		result;
	int		fd;
	int		i;
	char	*tmp;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error: file: can't open %s\n", str);
		return (EXIT_FAILURE);
	}
	result = file_content(fd);
	close(fd);
	return (result);
}
