/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:18:44 by aelison           #+#    #+#             */
/*   Updated: 2024/03/12 14:41:25 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_u(va_list args)
{
	unsigned int	tmp;
	int				result;

	result = 0;
	tmp = va_arg(args, unsigned int);
	result = ft_putnbr_unsigned(tmp);
	return (result);
}
