/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:30:59 by aelison           #+#    #+#             */
/*   Updated: 2025/02/27 07:35:20 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	make_vector(char *str)
{
	t_vect	p;
	char	**split;

	split = ft_split(str, ',');
	p.x = ft_atof(split[0]);
	p.y = ft_atof(split[1]);
	p.z = ft_atof(split[2]);
	ft_free_tab(split);
	return (p);
}

t_color	make_color(char *str)
{
	t_color	p;
	char	**split;

	p.r = 0;
	p.g = 0;
	p.b = 0;
	if (!str)
		return (p);
	split = ft_split(str, ',');
	p.r = ft_atoi(split[0]);
	p.g = ft_atoi(split[1]);
	p.b = ft_atoi(split[2]);
	ft_free_tab(split);
	return (p);
}
