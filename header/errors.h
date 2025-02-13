/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:30:33 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/13 10:05:17 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../header/struct.h"
# include "../libft/get_next_line/get_next_line.h"
# include <fcntl.h>

int		ft_error_init(int argc, char **argv);
int		for_ambient_l(t_scene *s, char **all, int *t);
int		for_camera(t_scene *s, char **all, int *t);
int		for_light(t_scene *s, char **all, int *t);
int		for_sphere(t_scene *s, char **all);
int		for_plane(t_scene *s, char **all);
int		for_cylinder(t_scene *s, char **all);
int		check_file(t_scene *s, char *str);
int		is_valid_format(char *str);
int		for_ambient_param(char **all);
int		for_camera_param(char **all);
int		for_light_param(char **all);
int		for_sphere_param(char **all);
int		for_plane_param(char **all);
int		for_cylinder_param(char **all);
void	init_x(int *i, int *obj, int *error, char **tmp);
#endif
