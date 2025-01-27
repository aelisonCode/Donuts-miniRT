/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nie.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:34:22 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 13:53:25 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_disp_vect(t_vect *vect)
{
	printf(" X: %f\n", vect->x);
	printf(" Y: %f\n", vect->y);
	printf(" Z: %f\n", vect->z);
}

void	ft_disp_content_a(t_a *a)
{
	printf("ratio: %f\n", a->ratio);
	printf("color:\n");
	printf("\n");
}

void	ft_disp_content_c(t_c *a)
{
	printf("fov: %f\n", a->fov);
	printf("view_point:\n");
	ft_disp_vect(&a->view_point);
	printf("direction:\n");
	ft_disp_vect(&a->direction);
	printf("\n");
}

void	ft_disp_content_l(t_l *a)
{
	printf("bright: %f\n", a->bright);
	printf("pos:\n");
	ft_disp_vect(&a->pos);
	printf("color:\n");
	printf("\n");
}
