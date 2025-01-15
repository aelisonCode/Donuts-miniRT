/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:10 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 08:33:40 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"

void	ft_filltab(int *tab, int len, int val);
void	ft_replace_str(char *to_change, char *set, char val);
void	ft_free_tab(char **ptr);
long	ft_count_char(char *target, char to_count);
#endif
