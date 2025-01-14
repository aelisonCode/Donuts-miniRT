/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:30:05 by aelison           #+#    #+#             */
/*   Updated: 2024/03/11 14:09:38 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_string(va_list args)
{
	char	*tmp;

	tmp = va_arg(args, char *);
	if (tmp == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(tmp);
	return (ft_strlen(tmp));
}
