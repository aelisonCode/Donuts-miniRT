/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:55:29 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/14 16:55:33 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/utils.h"
#include "../libft/ft_printf/ft_printf.h"

int ft_is_different(char *first, char *second)
{
	int i;

	i = 0;
	if (!first || !second)
		return (EXIT_FAILURE);
	while (first[i])
	{
		if (first[i] != second[i])
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	parse_object(char *str)
{
	int			result;
	char 		**split;
	static int	exist[6];

	split = ft_split(str, ' ');
	result = EXIT_FAILURE;
	ft_printf("start = %d\n", result);
	if (!split)
		return (result);
	if (ft_is_different(split[0], "A") == EXIT_SUCCESS)
	{
		result = for_ambient_l(split, &exist[0]);
		ft_printf("A with %d\n", result);
	}
	else if (ft_is_different(split[0], "C") == EXIT_SUCCESS)
	{
		result = for_camera(split, &exist[1]);
		ft_printf("C with %d\n", result);
	}
	else if (ft_is_different(split[0], "L") == EXIT_SUCCESS)
	{
		result = (for_light(split, &exist[2]));
		ft_printf("L with %d\n", result);
	}
	else if (ft_is_different(split[0], "sp") == EXIT_SUCCESS)
	{
		result = (for_sphere(split, &exist[3]));
		ft_printf("sp with %d\n", result);
	}
	else if (ft_is_different(split[0], "pl") == EXIT_SUCCESS)
	{
		result = (for_plane(split, &exist[4]));
		ft_printf("pl with %d\n", result);

	}
	else if (ft_is_different(split[0], "cy") == EXIT_SUCCESS)
	{
		result = (for_cylender(split, &exist[5]));
		ft_printf("cy with %d\n", result);
	}
	ft_free_tab(split);
	return (result);
}

int	check_file(char *str)
{
	int	result;
	int fd;
	char *tmp;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	tmp = "\0";
	result = EXIT_SUCCESS;
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (tmp)
		{
			ft_printf("======== tmp = %s =================\n", tmp);
			ft_replace_str(tmp, "\t\a\b\v\f\r", ' ');
			if (parse_object(tmp) == EXIT_FAILURE)
			{
				ft_printf("OH FAIL!\n");
				result = EXIT_FAILURE;
			}
			free(tmp);
		}
	}
	return (result);
}
