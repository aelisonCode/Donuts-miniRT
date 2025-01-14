/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:09:32 by aelison           #+#    #+#             */
/*   Updated: 2024/03/14 06:47:09 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexa_x(unsigned int i, char *hex)
{
	char	count;

	count = 0;
	if (i < 16)
	{
		ft_putchar(hex[i]);
		count++;
	}
	else
	{
		count = ft_hexa_x(i / 16, hex) + 1;
		ft_putchar(hex[i % 16]);
	}
	return (count);
}
