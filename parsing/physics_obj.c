/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:43:16 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 13:56:09 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_sp	*sphere(char **str)
{
	t_sp	*sp;

	sp = malloc(sizeof(t_sp));
	if (!sp)
		return (NULL);
	sp->center = make_vector(str[1]);
	sp->diameter = ft_atof(str[2]);
	sp->radius = sp->diameter / 2;
	ft_replace_str(str[3], "\n", '\0');
	sp->color = ft_atoi_base(str[3], 16);
	return (sp);
}

t_pl	*plane(char **str)
{
	t_pl	*pl;

	pl = malloc(sizeof(t_pl));
	if (!pl)
		return (NULL);
	pl->point = make_vector(str[1]);
	pl->direction = make_vector(str[2]);
	ft_replace_str(str[3], "\n", '\0');
	pl->color = ft_atoi_base(str[3], 16);
	return (pl);
}

t_cy	*cylender(char **str)
{
	t_cy	*cy;

	cy = malloc(sizeof(t_cy));
	if (!cy)
		return (NULL);
	cy->center = make_vector(str[1]);
	cy->direction = make_vector(str[2]);
	cy->diameter = ft_atof(str[3]);
	cy->radius = cy->diameter / 2;
	cy->height = ft_atof(str[4]);
	ft_replace_str(str[5], "\n", '\0');
	cy->color = ft_atoi_base(str[5], 16);
	return (cy);
}
