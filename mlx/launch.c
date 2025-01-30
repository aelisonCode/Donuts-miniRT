/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:33:31 by aelison           #+#    #+#             */
/*   Updated: 2025/01/30 14:35:53 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static void	write_line(t_mlx *mlx, char *mssg, t_vect pos, int color)
{
	char	*tmp;

	tmp = "no selected object";
	if (!mlx)
		return ;
	if (!mssg)
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color, tmp);
	else
		mlx_string_put(mlx->mlx_ptr, mlx->mlx_window, pos.x, pos.y, color,
			mssg);
}

char	*get_selected(t_scene *s)
{
	t_maps	*tmp;

	tmp = s->world;
	if (s->cam->selected == TRUE)
		return ("selected obj: CAMERA");
	if (s->light->selected == TRUE)
		return ("selected obj: LIGHT");
	return (NULL);
}

void	ft_menu(t_scene *s)
{
	t_mlx	*mlx;
	t_vect	pos_line;
	int		color;

	color = 0X00FF00;
	mlx = s->mlx;
	pos_line = init_vect(5, 30, 0);
	write_line(mlx, get_selected(s), pos_line, color);
}

void	ft_launch(t_scene *scene)
{
	t_mlx	*data;

	if (!scene)
		return ;
	data = scene->mlx;
	loop_screen(scene);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0,
		0);
	mlx_key_hook(data->mlx_window, ft_exec_input, scene);
	mlx_mouse_hook(data->mlx_window, on_button_pressed, scene);
	mlx_hook(data->mlx_window, 17, 1L << 17, ft_close_window, scene);
	mlx_loop(data->mlx_ptr);
}
