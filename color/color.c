/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:34:28 by aelison           #+#    #+#             */
/*   Updated: 2025/01/27 14:01:17 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	get_red(int color)
{
	return ((color >> 16) & 0XFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0XFF);
}

int	get_blue(int color)
{
	return ((color) & 0XFF);
}

int	create_color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	add_ambient_col(int color, double ambient)
{
	int	red;
	int	green;
	int	blue;
	int	res;

	red = get_red(color) * ambient;
	green = get_green(color) * ambient;
	blue = get_blue(color) * ambient;
	res = create_color(red, green, blue);
	return (res);
}
