/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:21:54 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 07:22:53 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

/*	Si appuie sur echappe quitte le programme	*/
int	ft_exec_input(int keycode, t_mlx *data)
{
	int	result;

	result = EXIT_FAILURE;
	if (data)
	{
		if (keycode == 65307)
			result = ft_close_window(data);
	}
	return (result);
}
