/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bigx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:55:51 by aelison           #+#    #+#             */
/*   Updated: 2024/03/14 06:46:16 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_bigx(va_list args)
{
	unsigned int	tmp;
	char			*hex;
	int				result;

	result = 0;
	hex = ft_strdup("0123456789ABCDEF");
	tmp = va_arg(args, unsigned int);
	result = ft_hexa_x(tmp, hex);
	free(hex);
	return (result);
}
