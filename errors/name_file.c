/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:04:53 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/25 14:56:53 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"

static int	check_rt(char *str)
{
	int		i;
	char	*res;
	int		status;

	i = 0;
	res = NULL;
	status = EXIT_FAILURE;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		res = ft_substr(str, i, ft_strlen(str));
		if (ft_strcmp(res, ".rt") == 0)
			status = EXIT_SUCCESS;
		else
			put_error("invalid extention!!!\n");
	}
	else
		put_error("the file must end with \".rt\" !\n");
	free(res);
	return (status);
}

int	check_name_file(char **argv)
{
	int	length;

	length = ft_strlen(argv[1]);
	if (length < 4 || check_rt(argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
