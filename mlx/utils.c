/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:04:52 by aelison           #+#    #+#             */
/*   Updated: 2025/01/20 07:06:52 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

int	ft_is_in_window(int x, int y)
{
	if (x >= 0 && x <= WINDOW_X)
	{
		if (y >= 0 && y <= WINDOW_Y)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	ft_put_pixel(t_mlx *data, int x, int y, int color)
{
	char	*tmp;

	if (ft_is_in_window(x, y) == EXIT_SUCCESS)
	{
		tmp = data->img_addr + (y * data->size_line + x * (data->byte_p_pixel
					/ 8));
		*(unsigned int *)tmp = color;
	}
}

int	ft_atoi_base(char *arg, int base)
{
	int	i;
	int	result;
	int	letter;

	i = 0;
	result = 0;
	if (arg[i] == '0' && arg[i + 1] == 'x')
		i += 2;
	else if (arg[i] == '0' && arg[i + 1] == 'X')
		i += 2;
	while (arg[i] != '\0' && arg[i] != '\n')
	{
		result = result * base;
		letter = ft_tolower(arg[i]);
		if (letter >= 'a' && letter <= 'f')
			result = result + (letter - 'a' + 10);
		else if (letter >= '0' && letter <= '9')
			result = result + (letter - '0');
		i++;
	}
	return (result);
}
