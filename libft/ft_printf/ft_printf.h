/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:08:48 by aelison           #+#    #+#             */
/*   Updated: 2024/03/14 06:43:53 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
int		ft_printf_char(va_list args);
int		ft_printf_string(va_list args);
int		ft_printf_decimal(va_list args);
int		ft_printf_ptr(va_list args);
int		ft_printf_u(va_list args);
int		ft_printf_x(va_list args);
int		ft_printf_bigx(va_list args);

void	ft_putchar(char c);
void	ft_putstr(char *s);

int		ft_hexa_x(unsigned int i, char *hex);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_hexa_ptr(unsigned long i);

int		ft_print_to_format(const char *format, va_list args);

#endif
