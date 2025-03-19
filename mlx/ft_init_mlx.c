/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:27:53 by aelison           #+#    #+#             */
/*   Updated: 2025/03/07 08:01:47 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static void	ft_img_init(t_scene *scene, int x, int y)
{
	t_mlx	*data;

	data = scene->mlx;
	data->img_ptr = mlx_new_image(data->mlx_ptr, x, y);
	if (data->img_ptr == NULL)
		ft_close_window(scene);
	data->img_addr = mlx_get_data_addr(data->img_ptr, &data->byte_p_pixel,
			&data->size_line, &data->endian);
	if (data->img_addr == NULL)
		ft_close_window(scene);
}

static void	ft_window_init(t_scene *s, t_mlx *data, char *title)
{
	data->mlx_window = mlx_new_window(data->mlx_ptr, WINDOW_X, WINDOW_Y, title);
	if (data->mlx_window == NULL)
	{
		ft_putendl_fd("Error\nMlx_new_window fail", STDERR_FILENO);
		ft_close_window(s);
		exit(EXIT_FAILURE);
	}
}

void	ft_init_events(t_scene *s)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		s->event[i].type = translation + i;
		if (i == 0)
			s->event[i].do_type = TRUE;
		else
			s->event[i].do_type = FALSE;
		i++;
	}
}

void	ft_init_scene(t_scene *data, double dist, char *title)
{
	t_mlx	*tmp;

	tmp = malloc(sizeof(t_mlx));
	if (!tmp)
		return ;
	tmp->mlx_ptr = mlx_init();
	if (tmp->mlx_ptr == NULL)
		exit(1);
	data->p = init_pjct(data->cam, dist);
	data->mlx = tmp;
	data->pixelize = FALSE;
	data->show_status = FALSE;
	data->show_ctrl = FALSE;
	ft_init_events(data);
	ft_img_init(data, WINDOW_X, WINDOW_Y);
	ft_window_init(data, tmp, title);
}
