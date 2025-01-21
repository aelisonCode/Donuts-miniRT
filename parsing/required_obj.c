/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   required_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42antananarivo.m  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 06:44:33 by aelison           #+#    #+#             */
/*   Updated: 2025/01/21 06:44:52 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/mini_rt.h"

t_a	*ft_create_camera(char *)
{
	t_a	*result;

	result = malloc(sizeof(t_a));
	if (!result)
		return (NULL);
	return (result);
}
