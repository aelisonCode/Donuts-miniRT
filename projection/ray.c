/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:50:33 by aelison           #+#    #+#             */
/*   Updated: 2025/02/13 09:57:11 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_render(t_scene *scene, int step)
{
	t_vect	incr;

	incr.y = 0;
	while (incr.y < WINDOW_Y)
	{
		incr.x = 0;
		while (incr.x < WINDOW_X)
		{
			scene->tmp_dist = 0;
			scene->nearest_obj = NULL;
			exec(scene, incr, step);
			incr.x += step;
		}
		incr.y += step;
	}
}

void	loop_screen(t_scene *s)
{
	if (s->pixelize == FALSE)
		ft_render(s, 1);
	else
		ft_render(s, fmax(1, WINDOW_X / 100.0));
}
