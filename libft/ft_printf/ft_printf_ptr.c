/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:19:06 by aelison           #+#    #+#             */
/*   Updated: 2024/03/12 10:09:24 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_ptr(va_list args)
{
	void	*tmp;
	int		result;

	result = 0;
	tmp = va_arg(args, void *);
	if (tmp == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		ft_putstr("0x");
		result = ft_hexa_ptr((unsigned long)tmp);
	}
	return (2 + result);
}
