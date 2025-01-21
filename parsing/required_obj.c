/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   required_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:44:33 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 11:23:36 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_vect	make_vector(char *str)
{
	t_vect p;
	char **split;

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

	split = ft_split(str, ',');
	p.r = ft_atof(split[0]);
	p.g = ft_atof(split[1]);
	p.b = ft_atof(split[2]);
	ft_free_tab(split);
	return (p);
}

t_a *ambient_l(char **str)
{
	t_a		*a;

	a = malloc(sizeof(t_a));
	if (!a)
		return (NULL);
	a->ratio = ft_atof(str[1]);
	a->color = make_color(str[2]);
	return (a);
}

t_c	*camera(char **str)
{
	t_c		*c;

	c = malloc(sizeof(t_c));
	if (!c)
		return (NULL);
	c->view_point = make_vector(str[1]);
	c->direction = make_vector(str[2]);
	c->fov = ft_atoi(str[3]);
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
	l->color = make_color(str[3]);
	return (l);
}

t_maps	*create_map(t_obj type, void *obj)
{
	t_maps *maps;
	
	maps = malloc(sizeof(t_maps));
	if (!maps)
		return (NULL);
	maps->type = type;
	maps->struct_obj = obj;
	maps->next = NULL;
	return (maps);
}

void	add_maps(t_maps **head, t_maps *new_elem)
{
	if (head == NULL || *head == NULL)
		*head = new_elem;
	else
	{
		new_elem->next = *head;
		*head = new_elem;
	}
}

void	ft_free_map(t_maps **head)
{
	t_maps	*tmp;

	while (*head)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp->struct_obj);
		free(tmp);
	}
	*head = NULL;
}

void	ft_disp_color(t_color	*color)
{
	ft_printf("R: %f\n", color->r);
	ft_printf("G: %f\n", color->g);
	ft_printf("G: %f\n", color->b);
}

void	ft_disp_type(t_maps	*curr)
{
	t_a	*tmp;

	if (curr->type == Ambient_l)
	{
		tmp = (t_a *)curr->struct_obj;
		ft_printf("type %d: Ambient_l\n", Ambient_l);
		ft_printf("ratio : %f\n", tmp->ratio);
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

void	ft_debug(t_maps	*head)
{
	ft_printf("=========================== start debug ============================\n");
	while (head)
	{
		ft_disp_type(head);
		head = head->next;
	}
}
