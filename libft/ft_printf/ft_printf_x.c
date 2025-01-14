/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:51:04 by aelison           #+#    #+#             */
/*   Updated: 2024/03/14 06:45:29 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_x(va_list args)
{
	unsigned int	tmp;
	char			*hex;
	int				result;

	result = 0;
	hex = ft_strdup("0123456789abcdef");
	tmp = va_arg(args, unsigned int);
	result = ft_hexa_x(tmp, hex);
	free(hex);
	return (result);
}
