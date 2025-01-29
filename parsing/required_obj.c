/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   required_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:44:33 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 13:57:39 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_a	*ambient_l(char **str)
{
	t_a	*a;

	a = malloc(sizeof(t_a));
	if (!a)
		return (NULL);
	a->ratio = ft_atof(str[1]);
	ft_replace_str(str[2], "\n", '\0');
	a->color = make_color(str[3]);
	a->color.color = create_color(a->color.r, a->color.g, a->color.b);
	return (a);
}

t_c	*camera(char **str)
{
	t_c	*c;

	c = malloc(sizeof(t_c));
	if (!c)
		return (NULL);
	c->ratio = round(WINDOW_X) / WINDOW_Y;
	c->view_point = make_vector(str[1]);
	c->direction = make_vector(str[2]);
	ft_replace_str(str[3], "\n", '\0');
	c->fov = ft_atoi(str[3]);
	c->selected = FALSE;
	return (c);
}

t_l	*light(char **str)
{
	t_l	*l;

	l = malloc(sizeof(t_l));
	if (!l)
		return (NULL);
	l->pos = make_vector(str[1]);
	l->bright = ft_atof(str[2]);
	ft_replace_str(str[3], "\n", '\0');
	l->color = make_color(str[3]);
	l->color.color = create_color(l->color.r, l->color.g, l->color.b);
	l->selected = FALSE;
	return (l);
}

t_maps	*create_map(t_obj type, void *obj)
{
	t_maps	*maps;

	maps = malloc(sizeof(t_maps));
	if (!maps)
		return (NULL);
	maps->type = type;
	maps->struct_obj = obj;
	maps->selected = FALSE;
	maps->next = NULL;
	return (maps);
}

void	add_maps(t_maps **head, t_maps *new_elem)
{
	if (head == NULL || *head == NULL)
	{
		*head = new_elem;
		new_elem->selected = TRUE;
	}
	else
	{
		new_elem->next = *head;
		*head = new_elem;
	}
}
