/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:30:33 by mravelon          #+#    #+#             */
/*   Updated: 2025/03/19 11:11:31 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../header/struct.h"
# include "../libft/get_next_line/get_next_line.h"
# include "utils.h"
# include <fcntl.h>

int		check_name_file(char **argv);
void	put_error(char *res);
int		check_void_file(int fd, t_scene *data, int *empty, int *status);
int		for_ambient_l(char **str, t_scene *data);
int		for_camera(char **str, t_scene *data);
int		for_ligth(char **str, t_scene *data);
int		for_sphere(char **str, t_scene *data);
int		for_plane(char **str, t_scene *data);
int		for_cylinder(char **str, t_scene *data);
int		for_camera_param(char **all);
int		for_light_param(char **all);
int		verify_ambient(char **str);
int		verify_camera(char **str);
int		verify_light(char **str);
int		verify_sphere(char **str);
int		verify_plane(char **str);
int		verify_cylinder(char **str);
void	init_x(int *i, int *obj, int *error, char **tmp);
int		valid_format(char **str);
int		check_zero(char *str);
#endif
