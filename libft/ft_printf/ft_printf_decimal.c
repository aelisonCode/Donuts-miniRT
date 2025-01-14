/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:59:31 by aelison           #+#    #+#             */
/*   Updated: 2024/03/13 08:03:25 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_decimal(va_list args)
{
	int		tmp;
	int		result;
	char	*convert;

	result = 0;
	tmp = va_arg(args, int);
	convert = ft_itoa(tmp);
	ft_putstr(convert);
	result = ft_strlen(convert);
	free(convert);
	return (result);
}
