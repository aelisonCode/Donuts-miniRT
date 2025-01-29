/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:30:33 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 09:03:12 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <fcntl.h>
# include "../libft/get_next_line/get_next_line.h"

int	ft_error_init(int argc, char **argv);
int	for_ambient_l(char **all, int *t);
int	for_camera(char **all, int *t);
int	for_light(char **all, int *t);
int	for_sphere(char **all);
int	for_plane(char **all);
int	for_cylender(char **all);
int	check_file(char *str);
int	is_valid_format(char *str);
int	for_ambient_param(char **all);
int	for_camera_param(char **all);
int	for_light_param(char **all);
int	for_sphere_param(char **all);
int	for_plane_param(char **all);
int	for_cylender_param(char **all);
#endif
