/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 08:55:02 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/27 17:42:13 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.h"

t_vect	div_vect(t_vect one, t_vect two)
{
	t_vect	new;

	new.x = one.x / two.x;
	new.y = one.y / two.y;
	new.z = one.z / two.z;
	return (new);
}

t_vect	normal_sp(t_vect inter, t_sp *obj)
{
	t_vect	res;

	res = ft_normalize(substraction(inter, obj->center));
	return (res);
}

t_vect	normal_pl(t_pl *obj)
{
	t_vect	res;

	res = obj->direction;
	return (res);
}
