/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:49:44 by aelison           #+#    #+#             */
/*   Updated: 2024/03/12 10:13:35 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexa_ptr(unsigned long i)
{
	char	*hex;
	char	count;

	count = 0;
	hex = ft_strdup("0123456789abcdef");
	if (i < 16)
	{
		ft_putchar(hex[i]);
		count++;
	}
	else
	{
		count = ft_hexa_ptr(i / 16) + 1;
		ft_putchar(hex[i % 16]);
	}
	free(hex);
	return (count);
}
