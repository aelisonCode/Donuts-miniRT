/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:56:01 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/26 13:35:15 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	mini_check_obj(char **cmd, int *error, t_scene *data)
{
	if (cmd[0][0] == '#')
		*error = EXIT_SUCCESS;
	else if (ft_strcmp(cmd[0], "A") == 0)
		*error = (*error) * for_ambient_l(cmd, data);
	else if (ft_strcmp(cmd[0], "C") == 0)
		*error = (*error) * for_camera(cmd, data);
	else if (ft_strcmp(cmd[0], "L") == 0)
		*error = (*error) * for_ligth(cmd, data);
	else if (ft_strcmp(cmd[0], "sp") == 0)
		*error = (*error) * for_sphere(cmd, data);
	else if (ft_strcmp(cmd[0], "pl") == 0)
		*error = (*error) * for_plane(cmd, data);
	else if (ft_strcmp(cmd[0], "cy") == 0)
		*error = (*error) * for_cylinder(cmd, data);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_obj(char **str, t_scene *data)
{
	char	**cmd;
	int		error;

	ft_replace_str(*str, "\t\n\v\f\r", ' ');
	if (is_empty(*str) == 1)
		return (EXIT_SUCCESS);
	cmd = ft_split(*str, ' ');
	error = 1;
	if (cmd == NULL)
		return (0);
	if (mini_check_obj(cmd, &error, data) == EXIT_FAILURE)
	{
		put_error("argment not valide !!! \n");
		ft_free_tab(cmd);
		return (EXIT_FAILURE);
	}
	ft_free_tab(cmd);
	return (error);
}

int	mini_check_void_file(int status, char *res, int empty, int i)
{
	if (status == EXIT_FAILURE)
	{
		if (res != NULL)
			free(res);
	}
	else if ((i == 0 && res == NULL) || empty == 1)
	{
		if (res != NULL)
			free(res);
		put_error("It's an empty file !\n");
		return (EXIT_FAILURE);
	}
	if (res != NULL)
		free(res);
	return (EXIT_SUCCESS);
}

int	check_void_file(int fd, t_scene *data, int *empty, int *status)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_strdup("");
	while (res != NULL)
	{
		if (res != NULL)
			free(res);
		res = get_next_line(fd);
		if (*status == EXIT_SUCCESS)
		{
			if (res != NULL)
				*empty = (*empty) * is_empty(res);
			if (*empty == 0 && res)
			{
				if (check_obj(&res, data) == EXIT_FAILURE)
					*status = EXIT_FAILURE;
			}
		}
		i++;
	}
	if (mini_check_void_file(*status, res, *empty, i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (*status);
}
