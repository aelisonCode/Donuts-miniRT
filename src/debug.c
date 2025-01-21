/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:59:07 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 14:36:53 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"
#include <stdio.h>

void	ft_disp_content_sp(t_maps *curr)
{
	t_sp	*a;

	a = curr->struct_obj;
	printf("center\n");
	ft_disp_vect(&a->center);
	printf("diameter: %f\n", a->diameter);
	printf("color:\n");
	ft_disp_color(&a->color);
	printf("\n");
}

void	ft_disp_content_pl(t_maps *curr)
{
	t_pl	*a;

	a = curr->struct_obj;
	printf("point:\n");
	ft_disp_vect(&a->point);
	printf("direction:\n");
	ft_disp_vect(&a->direction);
	printf("color:\n");
	ft_disp_color(&a->color);
	printf("\n");
}

void	ft_disp_content_cy(t_maps *curr)
{
	t_cy	*a;

	a = curr->struct_obj;
	printf("center\n");
	ft_disp_vect(&a->center);
	printf("direction\n");
	ft_disp_vect(&a->direction);
	printf("diameter: %f\n", a->diameter);
	printf("height: %f\n", a->height);
	printf("color:\n");
	ft_disp_color(&a->color);
	printf("\n");
}

void	ft_disp_type(t_maps *curr)
{
	if (curr->type == Ambient_l)
	{
		ft_printf("type %d: Ambient_l\n", Ambient_l);
		ft_disp_content_a(curr);
	}
	else if (curr->type == Camera)
	{
		ft_printf("type %d: Camera\n", Camera);
		ft_disp_content_c(curr);
	}
	else if (curr->type == Light)
	{
		ft_printf("type %d: Light\n", Light);
		ft_disp_content_l(curr);
	}
	else if (curr->type == Sphere)
	{
		ft_printf("type %d: Sphere\n", Sphere);
		ft_disp_content_sp(curr);
	}
	else if (curr->type == Plan)
	{
		ft_printf("type %d: plan\n", Plan);
		ft_disp_content_pl(curr);
	}
	else if (curr->type == Cylinder)
	{
		ft_printf("type %d: Cylender\n", Cylinder);
		ft_disp_content_cy(curr);
	}
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
