/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_program.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:51 by aelison           #+#    #+#             */
/*   Updated: 2025/03/05 16:54:52 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	error_check(int argc, char **argv, t_scene *data)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			if (errno == ENOENT)
				put_error("the file doesn't exist !!!\n");
			else if (errno == EACCES)
				put_error("permisson denied !!!\n");
			return (EXIT_FAILURE);
		}
		if (ft_error(fd, argv, data) == EXIT_FAILURE)
		{
			close(fd);
			ft_free_primary(data);
			ft_free_map(&data->world);
			return (EXIT_FAILURE);
		}
		close(fd);
		return (EXIT_SUCCESS);
	}
	put_error("wrong nb arg !!!\n");
	return (EXIT_FAILURE);
}

void	ft_init_data(t_scene *data)
{
	if (!data)
		return ;
	data->cam = NULL;
	data->amlight = NULL;
	data->light = NULL;
	data->world = NULL;
	data->mlx = NULL;
	data->nearest_obj = NULL;
	data->p = NULL;
}

int	main(int argc, char **argv)
{
	t_scene	data;

	ft_init_data(&data);
	if (error_check(argc, argv, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_scene(&data, 1.0, argv[1]);
	ft_launch(&data);
	return (EXIT_SUCCESS);
}
