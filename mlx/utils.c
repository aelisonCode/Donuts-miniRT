/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:04:52 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 07:06:52 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

void	ft_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*tmp;

	tmp = data->img_addr + (y * data->syze_line + x * (data->byte_p_pixel / 8));
	*(unsigned int *)tmp = color;
}
