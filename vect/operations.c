/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:38:53 by aelison           #+#    #+#             */
/*   Updated: 2025/01/22 08:53:10 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.h"
#include "../header/mini_rt.h"

t_vect	ft_normalize(t_vect to_norm)
{
	t_vect	res;
	double	lenght;

	lenght = vect_lenght(to_norm);
	if (lenght == 0)
	{
		ft_putendl_fd("error: vect lenght 0", STDERR_FILENO);
		ft_close_window(get_struct());
	}
	res.x /= lenght;
	res.y /= lenght;
	res.z /= lenght;
	return (res);
}

/*Give the vector direction from origin to target*/
t_vect	substraction(t_vect origin, t_vect target)
{
	t_vect	res;

	res.x = origin.x - target.x;
	res.y = origin.y - target.y;
	res.z = origin.z - target.z;
	return (res);
}

t_vect	sum(t_vect origin, t_vect target)
{
	t_vect	res;

	res.x = origin.x + target.x;
	res.y = origin.y + target.y;
	res.z = origin.z + target.z;
	return (res);
}

/*compare intersect/direction of the two vector*/
/*if res == 0, the two vect are perpendiculaire*/
/*if res > 0, the two vect are the same direction*/
/*if res < 0, the two vect are opposite direction*/
double	scalaire(t_vect origin, t_vect target)
{
	double	res;
	double	x;
	double	y;
	double	z;

	x = (origin.x * target.x);
	y = (origin.y * target.y);
	z = (origin.z * target.z);
	res = x + y + z;
	return (res);
}
