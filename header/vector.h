/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:51:25 by aelison           #+#    #+#             */
/*   Updated: 2025/02/27 17:56:43 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "../header/struct.h"
# include <math.h>

double	scalaire(t_vect origin, t_vect target);
t_vect	sum(t_vect origin, t_vect target);
t_vect	substraction(t_vect origin, t_vect target);
t_vect	cross(t_vect origin, t_vect target);
t_vect	vect_dot_val(t_vect target, double val);
double	get_angle(t_vect a, t_vect b);
double	distances(t_vect o, t_vect d);
t_vect	ft_normalize(t_vect to_norm);
double	subpow(double o, double d);
t_vect	div_vect(t_vect one, t_vect two);
t_vect	normal_sp(t_vect inter, t_sp *obj);
t_vect	init_vect(double x, double y, double z);
double	vect_length(t_vect to_check);
t_vect	normal_pl(t_pl *obj);
int		check_normalize(t_vect x);
#endif
