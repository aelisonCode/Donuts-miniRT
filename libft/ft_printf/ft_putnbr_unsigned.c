/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:45:34 by aelison           #+#    #+#             */
/*   Updated: 2024/03/11 13:53:32 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	result;

	result = 0;
	if (n <= 9)
	{
		ft_putchar(n + '0');
		result++;
	}
	else
	{
		result = ft_putnbr_unsigned(n / 10) + 1;
		ft_putchar((n % 10) + '0');
	}
	return (result);
}
