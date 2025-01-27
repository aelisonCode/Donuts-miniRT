/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:59:07 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 13:53:47 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_disp_content_sp(t_maps *curr)
{
	t_sp	*a;

	a = curr->struct_obj;
	printf("center\n");
	ft_disp_vect(&a->center);
	printf("diameter: %f\n", a->diameter);
	printf("color:\n");
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
	printf("\n");
}

void	ft_disp_type(t_maps *curr)
{
	ft_printf("\n============== New object ================\n");
	if (curr->type == Sphere)
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
	while (head)
	{
		ft_disp_type(head);
		head = head->next;
	}
}
