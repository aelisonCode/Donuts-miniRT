/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:53:34 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/21 10:17:17 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_object
{
	Ambient_l,
	Camera,
	Light,
	Sphere,
	Plan,
	Cylinder
}					t_obj;

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_window;
	void			*img_ptr;
	char			*img_addr;
	int				byte_p_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct s_a
{
	double			ratio;
	t_color			color;
}					t_a;

typedef struct s_c
{
	t_vect			view_point;
	t_vect			direction;
	int				fov;
}					t_c;

typedef struct s_l
{
	t_vect			pos;
	double			bright;
	t_color			color;
}					t_l;

typedef struct s_sp
{
	t_vect			center;
	double			diameter;
	t_color			color;
}					t_sp;

typedef struct s_pl
{
	t_vect			point;
	t_vect			direction;
	t_color			color;
}					t_pl;

typedef struct s_cy
{
	t_vect			center;
	t_vect			direction;
	double			diameter;
	double			height;
	t_color			color;
}					t_cy;

typedef struct s_maps
{
	t_obj			type;
	void			*struct_obj;
	struct s_maps	*next;
}					t_maps;

typedef struct	s_scene
{
	t_mlx	*mlx;
	t_maps	*world;
}	t_scene;

#endif
