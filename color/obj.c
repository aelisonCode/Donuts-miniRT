/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:46:14 by aelison           #+#    #+#             */
/*   Updated: 2025/02/13 10:36:26 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_color	get_col_sp(t_sp *obj)
{
	return (obj->color);
}

t_color	get_col_pl(t_pl *obj)
{
	return (obj->color);
}

t_color	get_col_cy(t_cy *obj)
{
	return (obj->color);
}

t_color	get_col(t_maps *obj)
{
	t_color	tmp;

	tmp.r = 0XFFFFFF;
	tmp.g = 0XFFFFFF;
	tmp.b = 0XFFFFFF;
	tmp.color = create_color(tmp.r, tmp.g, tmp.b);
	if (!obj)
		return (tmp);
	if (obj->type == Sphere)
		return (get_col_sp(obj->struct_obj));
	if (obj->type == Plane)
		return (get_col_pl(obj->struct_obj));
	if (obj->type == Cylinder)
		return (get_col_cy(obj->struct_obj));
	return (tmp);
}
