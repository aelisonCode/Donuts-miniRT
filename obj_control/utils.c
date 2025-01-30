/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:56:01 by aelison           #+#    #+#             */
/*   Updated: 2025/01/30 14:25:08 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	compute_intersec_pts(t_ray *r, double t)
{
	t_vect	result;

	result = sum(r->origin, vect_dot_val(r->direction, t));
	return (result);
}

int	cmp_dist(t_scene *s, t_vect *pts, int new_col)
{
	double	lenght_pts;
	t_c		*cam;

	cam = s->cam;
	lenght_pts = vect_lenght(substraction(*pts, cam->view_point));
	if (s->dist_curr == -1)
	{
		s->dist_curr = lenght_pts;
		s->color_to_put = new_col;
		return (EXIT_SUCCESS);
	}
	else if (s->dist_curr > lenght_pts)
	{
		s->dist_curr = lenght_pts;
		s->color_to_put = new_col;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	do_intersec_other(t_scene *s, t_maps *other, t_ray *r)
{
	t_vect	solution;
	t_vect	test;

	test = init_vect(0, 0, 0);
	if (!s || !other || !s)
		return ;
	while (other)
	{
		if (other->type == Sphere)
		{
			if (ft_intersec_sp(other->struct_obj, r, &solution) == EXIT_SUCCESS)
			{
				cmp_dist(s, &solution, exec_sp(s, other, r, test));
			}
		}
		other = other->next;
	}
}
