/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_to_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:58:00 by aelison           #+#    #+#             */
/*   Updated: 2025/02/06 11:21:04 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	ft_mouse_to_sp(t_scene *s, t_maps *ptr, t_ray *r, int do_move)
{
	double	t;
	t_vect	solution;
	t_color	tmp;

	if (ft_intersec_sp(ptr->struct_obj, r, &solution, &t) == EXIT_SUCCESS)
	{
		if (do_move == 0)
			return (select_state(s, ptr));
		else
		{
			tmp = get_col(ptr);
			return (rand_col(&tmp));
		}
	}
	return (EXIT_FAILURE);
}

int	ft_mouse_to_pl(t_scene *s, t_maps *ptr, t_ray *r, int do_move)
{
	double	t;
	t_vect	solution;
	t_color	tmp;

	if (ft_intersec_pl(ptr->struct_obj, r, &solution, &t) == EXIT_SUCCESS)
	{
		if (do_move == 0)
			return (select_state(s, ptr));
		else
		{
			tmp = get_col(ptr);
			return (rand_col(&tmp));
		}
	}
	return (EXIT_FAILURE);
}

int	ft_mouse_to_cy(t_scene *s, t_maps *ptr, t_ray *r, int do_move)
{
	double	t;
	t_vect	solution;
	t_color	tmp;

	if (ft_intersec_cy(ptr->struct_obj, r, &solution, &t) == EXIT_SUCCESS)
	{
		if (do_move == 0)
			return (select_state(s, ptr));
		else
		{
			tmp = get_col(ptr);
			return (rand_col(&tmp));
		}
	}
	return (EXIT_FAILURE);
}

int	ft_mouse_to_obj(t_scene *s, t_maps *ptr, t_ray *r, int do_move)
{
	int	val;

	val = EXIT_FAILURE;
	if (ptr->type == Sphere)
		val = ft_mouse_to_sp(s, ptr, r, do_move);
	if (ptr->type == Plane)
		val = ft_mouse_to_pl(s, ptr, r, do_move);
	if (ptr->type == Cylinder)
		val = ft_mouse_to_cy(s, ptr, r, do_move);
	return (val);
}
