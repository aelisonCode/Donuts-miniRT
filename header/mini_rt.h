/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:09:40 by aelison           #+#    #+#             */
/*   Updated: 2025/02/07 11:09:58 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../header/color.h"
# include "../header/errors.h"
# include "../header/utils.h"
# include "../header/vector.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "struct.h"
# include <math.h>
# include <stdio.h>

/*MLX FUNCTIONS*/
int				on_button_pressed(int button, int x, int y, void *param);
void			ft_launch(t_scene *scene);
int				ft_exec_input(int keycode, t_scene *data);
int				ft_close_window(t_scene *data);
int				ft_is_in_window(int x, int y);
void			ft_init_scene(t_scene *data, double dist, char *title);
void			gen_new_image(t_scene *scene);

void			ft_free_mlx(t_scene *data);
void			ft_free_map(t_maps **head);

void			ft_put_pixel(t_mlx *data, int x, int y, int color);
void			ft_launch(t_scene *data);
t_maps			*create_map(t_obj type, void *obj);
void			add_maps(t_maps **head, t_maps *new_elem);

void			ft_translation(t_vect *point, int move, double incr);
void			ft_scale(double *value, int move, double incr);
void			ft_rotate(t_vect *direction, int keycode, int incr_deg);

int				select_primary(t_scene *scene, int select);
t_obj			is_primary_selected(t_scene *scene);
void			control_primary(t_scene *scene, t_obj type, int keycode);

int				ft_released(int keycode, t_scene *s);
int				ft_pressed(int keycode, t_scene *s);
int				select_next_obj(t_scene *s);
char			*get_selected(t_scene *s, t_maps **ptr);
void			exec_obj_event(t_scene *s, int keycode);
int				ft_mouse_to_obj(t_scene *s, t_maps *ptr, t_ray *r, int do_move);
int				ft_show_control(t_scene *s);
void			select_mod(t_scene *s, int keycode);

/*OBJECT*/
t_a				*ambient_l(char **str);
t_c				*camera(char **str);
t_l				*light(char **str);
t_sp			*sphere(char **str);
t_pl			*plane(char **str);
t_cy			*cylinder(char **str);
int				select_state(t_scene *s, t_maps *ptr);
t_color			get_col(t_maps *obj);
int				rand_col(t_color *col);
void			change_state(int *to_change);

void			ft_center(t_vect *to_change, int keycode, double incr);
void			ft_rotation(t_vect *to_change, int keycode, double incr);
void			ft_diameter(double *diameter, double *radius, int keycode,
					double incr);
void			ft_height(double *height, int keycode, double incr);
void			ft_color(t_color *ref, int to_change, int keycode, int incr);
/*SPHERE*/
int				ft_intersec_sp(t_sp *obj, t_ray *r, t_vect *solution,
					double *t);
int				exec_sp(t_scene *s, t_maps *curr, t_ray *r);
void			ft_sp_event(t_scene *data, t_maps *curr, int keycode,
					double incr);

/*CYLENDER*/
int				ft_intersec_cy(t_cy *obj, t_ray *r, t_vect *solution,
					double *t);
int				exec_cy(t_scene *s, t_maps *curr, t_ray *r);
void			ft_cy_event(t_scene *s, t_maps *obj, int keycode, double incr);
int				compute_edge(t_cy *obj, t_ray *r, t_vect *solution);
t_vect			ft_normal_cy(t_ray *r, t_cy *obj, double t, t_vect point);

/*PLANE*/
int				ft_intersec_pl(t_pl *obj, t_ray *ray, t_vect *res, double *t);
void			ft_pl_event(t_scene *s, t_maps *obj, int keycode, double incr);
int				exec_pl(t_scene *s, t_maps *obj, t_ray *r);

/*VECTOR*/
t_vect			make_vector(char *str);
t_color			make_color(char *str);
double			get_root(double a, double b, double disc);
t_ray			create_ray(t_vect *origin, t_projection *p, int x, int y);
t_projection	*init_pjct(t_c *cam, double dist);
void			loop_screen(t_scene *scene);

/*EFFECT*/
/* int				check_sp(t_scene *s, t_sp *obj, t_vect *ref_pts, */
/* 					t_maps *target, double lambert); */
/* int				check_pl(t_scene *s, t_pl *obj, t_vect *ref_pts, */
/* 					t_maps *target, double lambert); */
/* int				check_cy(t_scene *s, t_cy *obj, t_vect *ref_pts, */
/* 					t_maps *target, double lambert); */
int				check_pl(t_scene *s, t_pl *obj, t_vect *ref_pts,
					t_maps *target);
int				check_cy(t_scene *s, t_cy *obj, t_vect *ref_pts,
					t_maps *target);
int				check_sp(t_scene *s, t_sp *obj, t_vect *ref_pts,
					t_maps *target);

void			ft_scale_color(int *color_base, int keycode, int incr);
/*OTHER*/
int				cmp_dist(t_scene *s, double dist, int new_col);
t_vect			compute_intersec_pts(t_ray *r, double t);
int				ft_add_shadow(t_scene *s, t_maps *target, t_vect *ref_pts);
#endif
