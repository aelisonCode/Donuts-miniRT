/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:27:09 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/14 16:29:54 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int		valid_format_aux(char *str, int *i)
{
	while (str[*i] && ft_isdigit(str[*i]) != 0)
		(*i)++;
	if (str[*i] == '.' || str[*i] == ',')
	{
		if (ft_isdigit(str[(*i) + 1]) == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		is_valid_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-'  || str[i] == '+') && ft_isdigit(str[i + 1]) == 0)
			return (EXIT_FAILURE);
		else if (ft_isdigit(str[i]) != 0)
		{
			if (valid_format_aux(str, &i) == EXIT_FAILURE)
					return (EXIT_FAILURE);
		}
		else if (str[i] != '-' && str[i] != '+')
		{
			ft_printf("again ? %c\n", str[i]);
			return (EXIT_FAILURE);
		}
		if (str[i])
			i++;
	}
	return (EXIT_SUCCESS);
}

int	for_ambient_l(char **all, int *t)
{
	int i;
	int cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 3)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}

int	for_camera(char **all, int *t)
{
	int i;
	int cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 4)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}

int	for_light(char **all, int *t)
{
	int i;
	int cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 4)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}
int	for_sphere(char **all, int *t)
{
	int i;
	int cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		ft_printf("arg[%d] = %s\n", i, all[i]);
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	ft_printf("SPHERE:\t%d\t%s\n", i, all[i - 1]);
	if (i != 4)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}

int	for_plane(char **all, int *t)
{
	int i;
	int cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 4)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);
}

int	for_cylender(char **all, int *t)
{
	int i;
	int cont;

	i = 1;
	if (*t != 0)
		return (EXIT_FAILURE);
	while (all[i])
	{
		if (is_valid_format(all[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (i != 6)
		return (EXIT_FAILURE);
	(*t)++;
	return (EXIT_SUCCESS);

}
