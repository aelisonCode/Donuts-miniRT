/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:54 by aelison           #+#    #+#             */
/*   Updated: 2025/03/06 15:57:12 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../header/struct.h"

int		create_color(int red, int green, int blue);
int		ambient_color(t_color *c, t_scene *s);
double	ambient(int c, t_scene *s, int a_c);
int		diffus_color(t_color *color, t_l *light, t_scene *scene, t_ray *ray);
void	ft_exec_color(t_scene *s, int keycode, int incr, t_color *to_change);

#endif
