/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_to_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:58:00 by aelison           #+#    #+#             */
/*   Updated: 2025/02/13 10:38:09 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	ft_mouse_to_sp(t_maps *ptr, t_ray *r)
{
	double	t;

	if (ft_intersec_sp(ptr->struct_obj, r, &t) == EXIT_SUCCESS)
		return (t);
	return (-1);
}

static int	ft_mouse_to_pl(t_maps *ptr, t_ray *r)
{
	double	t;

	if (ft_intersec_pl(ptr->struct_obj, r, &t) == EXIT_SUCCESS)
		return (t);
	return (-1);
}

static int	ft_mouse_to_cy(t_maps *ptr, t_ray *r)
{
	double	t;

	if (ft_intersec_cy(ptr->struct_obj, r, &t) == EXIT_SUCCESS)
		return (t);
	return (-1);
}

int	ft_mouse_to_obj(t_maps *ptr, t_ray *r)
{
	int	val;

	val = -1;
	if (ptr->type == Sphere)
		val = ft_mouse_to_sp(ptr, r);
	if (ptr->type == Plane)
		val = ft_mouse_to_pl(ptr, r);
	if (ptr->type == Cylinder)
		val = ft_mouse_to_cy(ptr, r);
	return (val);
}
