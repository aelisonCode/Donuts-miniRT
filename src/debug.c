/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:59:07 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 12:59:29 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_disp_color(t_color *color)
{
	printf("R: %f\n", color->r);
	printf("G: %f\n", color->g);
	printf("B: %f\n", color->b);
}

void	ft_disp_type(t_maps *curr)
{
	t_a	*tmp;

	if (curr->type == Ambient_l)
	{
		tmp = (t_a *)curr->struct_obj;
		ft_printf("type %d: Ambient_l\n", Ambient_l);
		printf("ratio : %f\n", tmp->ratio);
		ft_disp_color(&tmp->color);
	}
	else if (curr->type == Camera)
		ft_printf("type %d: Camera\n", Camera);
	else if (curr->type == Light)
		ft_printf("type %d: Light\n", Light);
	else if (curr->type == Sphere)
		ft_printf("type %d: Sphere\n", Sphere);
	else if (curr->type == Plan)
		ft_printf("type %d: plan\n", Plan);
	else if (curr->type == Cylinder)
		ft_printf("type %d: Cylender\n", Cylinder);
}

void	ft_debug(t_maps *head)
{
	ft_printf("========== start debug =========\n");
	while (head)
	{
		ft_disp_type(head);
		head = head->next;
	}
}
