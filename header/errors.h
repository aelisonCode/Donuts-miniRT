/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:30:33 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/14 16:55:28 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
#define ERRORS_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"


void	ft_error_init(int argc, char **argv);
int		for_ambient_l(char **all, int *t);
int		for_camera(char **all, int *t);
int		for_light(char **all, int *t);
int		for_sphere(char **all, int *t);
int		for_plane(char **all, int *t);
int		for_cylender(char **all, int *t);
int		check_file(char *str);
#endif

