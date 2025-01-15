/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:09:40 by aelison           #+#    #+#             */
/*   Updated: 2025/01/14 15:29:09 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../header/errors.h"

typedef struct s_mlx
{
	int		w_sizex;
	int		w_sizey;
	void	*mlx_ptr;
	void	*mlx_window;
}	t_mlx;

typedef enum e_object
{
	Ambient_l,
	Camera,
	Light,
	Sphere,
	Plan,
	Cylinder
}	t_obj;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vect;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

/*			MLX FUNCTIONS			*/
void	ft_init_mlx(t_mlx *data, char *title);
int		ft_exec_input(int keycode, t_mlx *data);
int		ft_close_window(t_mlx *data);

#endif
