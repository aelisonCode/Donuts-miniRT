/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:38:53 by aelison           #+#    #+#             */
/*   Updated: 2025/01/23 15:19:03 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.h"
#include "../libft/libft.h"
#include <unistd.h>

t_vect	ft_normalize(t_vect to_norm)
{
	t_vect	res;
	double	lenght;

	lenght = vect_lenght(to_norm);
	if (lenght == 0)
	{
		ft_putendl_fd("error: vect lenght 0", STDERR_FILENO);
		return (init_vect(0, 0, 0));
	}
	res.x = to_norm.x / lenght;
	res.y = to_norm.y / lenght;
	res.z = to_norm.z / lenght;
	return (res);
}

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

t_vect	cross(t_vect origin, t_vect target)
{
	t_vect	res;

	res.x = origin.y * target.z - origin.z * target.y;
	res.y = origin.z * target.x - origin.x * target.z;
	res.z = origin.x * target.y - origin.y * target.x;
	return (res);
}

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
