/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_effect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:16:15 by aelison           #+#    #+#             */
/*   Updated: 2025/02/07 13:45:01 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

static int	ft_exec_obj(t_scene *s, t_maps *ptr, t_vect *ref_pts,
		t_maps *target)
{
	int	val;

	val = -1;
	if (ptr->type == Sphere)
	{
		val = check_sp(s, ptr->struct_obj, ref_pts, target);
		if (val != -1)
			return (val);
	}
	if (ptr->type == Plane)
	{
		val = check_pl(s, ptr->struct_obj, ref_pts, target);
		if (val != -1)
			return (val);
	}
	if (ptr->type == Cylinder)
	{
		val = check_cy(s, ptr->struct_obj, ref_pts, target);
		if (val != -1)
			return (val);
	}
	return (val);
}

int	ft_add_shadow(t_scene *s, t_maps *target, t_vect *ref_pts)
{
	int		val;
	t_maps	*tmp;

	val = -1;
	if (!s || !target || !ref_pts)
		return (val);
	tmp = s->world;
	while (tmp)
	{
		if (target->id != tmp->id)
		{
			val = ft_exec_obj(s, tmp, ref_pts, target);
			if (val != -1)
				return (val);
		}
		tmp = tmp->next;
	}
	return (val);
}
