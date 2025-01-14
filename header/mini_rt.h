/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:09:40 by aelison           #+#    #+#             */
/*   Updated: 2024/12/17 09:04:32 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_mlx
{
	int		w_sizex;
	int		w_sizey;
	void	*mlx_ptr;
	void	*mlx_window;
}	t_mlx;

/*			ERROR FUNCTIONS			*/
void	ft_error_init(int argc, char **argv);

/*			MLX FUNCTIONS			*/
void	ft_init_mlx(t_mlx *data, char *title);
int		ft_exec_input(int keycode, t_mlx *data);
int		ft_close_window(t_mlx *data);

#endif
