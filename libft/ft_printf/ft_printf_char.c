/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:26:16 by aelison           #+#    #+#             */
/*   Updated: 2024/03/11 11:38:15 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_char(va_list args)
{
	int	tmp;

	tmp = va_arg(args, int);
	ft_putchar((char)tmp);
	return (1);
}
