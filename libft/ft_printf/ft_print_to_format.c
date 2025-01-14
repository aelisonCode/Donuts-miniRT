/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_to_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:01:50 by aelison           #+#    #+#             */
/*   Updated: 2024/03/14 07:39:08 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_to_format(const char *format, va_list args)
{
	int	result;

	result = 0;
	if (*(format + 1) == 'c')
		result = ft_printf_char(args);
	else if (*(format + 1) == 's')
		result = ft_printf_string(args);
	else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		result = ft_printf_decimal(args);
	else if (*(format + 1) == 'p')
		result = ft_printf_ptr(args);
	else if (*(format + 1) == 'u')
		result = ft_printf_u(args);
	else if (*(format + 1) == 'x')
		result = ft_printf_x(args);
	else if (*(format + 1) == 'X')
		result = ft_printf_bigx(args);
	else if (*(format + 1) == '%')
	{
		ft_putchar('%');
		result = 1;
	}
	return (result);
}
