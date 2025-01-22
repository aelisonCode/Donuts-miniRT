/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:01 by aelison           #+#    #+#             */
/*   Updated: 2025/01/22 09:13:11 by aelison          ###   ########.fr       */
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

double	vect_lenght(t_vect to_check)
{
	double	res;

	res = sqrt(pow(to_check.x, 2) + pow(to_check.y, 2) + pow(to_check.z, 2));
	return (res);
}
