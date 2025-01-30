/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:53:34 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/30 15:18:15 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WINDOW_X 1000
# define WINDOW_Y 600

# define TRUE 1
# define FALSE 0

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
# define Z_UP 65431
# define Z_DOWN 65433

# define SCALE_UP 65451
# define SCALE_DOWN 65453
# define CHANGE_OBJ 65289

# define COEFF_REFCT 1.0
# define REFRACTION_AM 0.5

typedef enum e_object
{
	Ambient_l,
	Camera,
	Light,
	Sphere,
	Plane,
	Cylinder,
	Non_object
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
	t_color			color;
}					t_a;

typedef struct s_c
{
	t_vect			view_point;
	t_vect			direction;
	double			ratio;
	double			fov;
	int				selected;
}					t_c;

typedef struct s_l
{
	t_vect			pos;
	double			bright;
	t_color			color;
	int				selected;
}					t_l;

typedef struct s_sp
{
	t_vect			center;
	double			diameter;
	double			radius;
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
	int				selected;
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
	double			dist_curr;
	int				color_to_put;
}					t_scene;

#endif
