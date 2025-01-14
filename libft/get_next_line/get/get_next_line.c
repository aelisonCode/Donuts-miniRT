/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:38:04 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/14 16:48:44 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char *get_next_line(int fd, int i)
{
	char *buffer;
	static char *stock;
	char line[1000000];
	static int bytes;
	static int buffer_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		if (buffer_index <= bytes)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes <= 0)
				break;
			buffer[bytes] = '\0';
			if (stock != NULL)
				free(stock);
			stock = ft_strdup(buffer);
		}
		line[i++] = stock[buffer_index++];
		if (line[i - 1] == '\n')
			break;
	}
	if (buffer != NULL)
		free(buffer);
	if (i == 0 || bytes < 0)
	{
		if (stock != NULL)
			free(stock);
		return (NULL);
	}
	line[i] = '\0';
	return (ft_strdup(line));
}
