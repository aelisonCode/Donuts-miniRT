/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:01 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 15:49:30 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.h"

t_vect	init_vect(double x, double y, double z)
{
	t_vect	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

double	vect_length(t_vect to_check)
{
	double	res;

	res = sqrt(pow(to_check.x, 2) + pow(to_check.y, 2) + pow(to_check.z, 2));
	return (res);
}

t_vect	vect_dot_val(t_vect target, double val)
{
	t_vect	res;

	res.x = target.x * val;
	res.y = target.y * val;
	res.z = target.z * val;
	return (res);
}

double	get_angle(t_vect a, t_vect b)
{
	double	numerator;
	double	denominator;
	double	res;

	numerator = scalaire(a, b);
	denominator = vect_length(a) * vect_length(b);
	if (denominator == 0)
		return (0);
	res = acos(numerator / denominator);
	res = res * (180 / M_PI);
	return (res);
}

double	get_root(double a, double b, double disc)
{
	double	r_1;
	double	r_2;

	if (disc == 0)
	{
		r_1 = ((-b) / (2 * a));
		if (r_1 < 0)
			return (-1);
		return (r_1);
	}
	r_1 = (-b - sqrt(disc)) / (2 * a);
	r_2 = (-b + sqrt(disc)) / (2 * a);
	if (r_1 > EPSILON && r_2 > EPSILON)
		return (fmin(r_1, r_2));
	else if (r_1 > EPSILON)
		return (r_1);
	else if (r_2 > EPSILON)
		return (r_2);
	return (-1);
}
