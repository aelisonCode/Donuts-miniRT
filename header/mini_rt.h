/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:09:40 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 11:25:08 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../header/errors.h"
# include "../header/utils.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "math.h"
# include "struct.h"

# define WINDOW_X 1920
# define WINDOW_Y 1080

/*MLX FUNCTIONS*/
int			ft_exec_input(int keycode, t_scene *data);
int			ft_close_window(t_scene *data);
int			ft_is_in_window(int x, int y);
void		ft_init_scene(t_scene *data, char *title);

void		ft_free_mlx(t_scene *data);
void		ft_free_map(t_maps **head);

void		ft_put_pixel(t_mlx *data, int x, int y, int color);
void		ft_launch(t_scene *data);
void		*get_struct(void);
t_maps		*create_map(t_obj type, void *obj);
void		add_maps(t_maps **head, t_maps *new_elem);
t_a			*ambient_l(char **str);

/*DEBUG*/
void	ft_debug(t_maps	*head);
#endif
