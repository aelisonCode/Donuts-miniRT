/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:09:40 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 07:40:40 by aelison          ###   ########.fr       */
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

# define WINDOW_X 1920
# define WINDOW_Y 1080

typedef enum e_object
{
	Ambient_l,
	Camera,
	Light,
	Sphere,
	Plan,
	Cylinder
}			t_obj;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vect;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}			t_color;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*img_ptr;
	char	*img_addr;
	int		byte_p_pixel;
	int		size_line;
	int		endian;
}			t_mlx;

/*MLX FUNCTIONS*/
int			ft_exec_input(int keycode, t_mlx *data);
int			ft_close_window(t_mlx *data);
int			ft_is_in_window(int x, int y);
void		ft_init_mlx(t_mlx *data, char *title);
void		ft_free_mlx(t_mlx *data);
void		ft_put_pixel(t_mlx *data, int x, int y, int color);
#endif
