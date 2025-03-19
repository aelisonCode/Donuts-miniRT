/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:07:22 by aelison           #+#    #+#             */
/*   Updated: 2025/03/06 10:29:35 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/struct.h"
#include "../header/mini_rt.h"

void	ft_protect_event(t_base event[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (event[i].do_type != FALSE)
			break ;
		i++;
	}
	if (i < 10)
		return ;
	else
		event[0].do_type = TRUE;
}

int	ft_get_event_state(t_base event[10], t_command search)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (event[i].type == search)
			return (event[i].do_type);
		i++;
	}
	return (-1);
}

void	ft_define_base(t_base *to_change, t_command obj, int value)
{
	to_change->type = obj;
	to_change->do_type = value;
}

void	ft_lock_event(t_base event[10], t_command not_lock)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (event[i].type != not_lock)
			event[i].do_type = FALSE;
		i++;
	}
}

void	ft_select_event(t_base event[10], t_command to_exec, int do_lock_else)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (event[i].type == to_exec)
		{
			if (event[i].do_type == FALSE)
				event[i].do_type = TRUE;
			else if (event[i].do_type == TRUE)
				event[i].do_type = FALSE;
			if (do_lock_else == TRUE)
				ft_lock_event(event, to_exec);
			return ;
		}
		i++;
	}
}
