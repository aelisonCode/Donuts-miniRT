/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:54 by aelison           #+#    #+#             */
/*   Updated: 2025/01/28 13:36:00 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../header/struct.h"

int	get_red(int color);
int	get_green(int color);
int	get_blue(int color);
int	create_color(int red, int green, int blue);
int	gen_color(int color, t_a *ambient_struct, double lambert);
int	create_color(int red, int green, int blue);
#endif
