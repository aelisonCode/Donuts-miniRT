/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:53:34 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/27 13:52:49 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WINDOW_X 1000
# define WINDOW_Y 500

# define LEFT_BUTTON 1
# define RIGHT_BUTTON 3
# define MID_BUTTON 2

# define K_ESCAPE 65307
# define CAMERA 99
# define LIGHT 108
# define AMBIENT 97

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define SCALE_UP 65451
# define SCALE_DOWN 65453

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

typedef struct s_ray
{
	t_vect			origin;
	t_vect			direction;
}					t_ray;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

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
	int				color;
}					t_a;

typedef struct s_c
{
	t_vect			view_point;
	t_vect			direction;
	double			ratio;
	double			fov;
}					t_c;

typedef struct s_l
{
	t_vect			pos;
	double			bright;
	int				color;
}					t_l;

typedef struct s_sp
{
	t_vect			center;
	double			diameter;
	double			radius;
	int				color;
}					t_sp;

typedef struct s_pl
{
	t_vect			point;
	t_vect			direction;
	int				color;
}					t_pl;

typedef struct s_cy
{
	t_vect			center;
	t_vect			direction;
	double			diameter;
	double			height;
	int				color;
	double			radius;
}					t_cy;

typedef struct s_projection
{
	t_vect			top_left;
	t_vect			width_dir;
	t_vect			height_dir;
	double			width;
	double			height;
}					t_projection;

typedef struct s_maps
{
	t_obj			type;
	void			*struct_obj;
	struct s_maps	*next;
}					t_maps;

typedef struct s_scene
{
	t_mlx			*mlx;
	t_a				*amlight;
	t_c				*cam;
	t_l				*light;
	t_maps			*world;
	t_projection	*p;
}					t_scene;

#endif
