/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:10 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/15 17:19:28 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "stdio.h"

void	ft_filltab(int *tab, int len, int val);
void	ft_replace_str(char *to_change, char *set, char val);
void	ft_free_tab(char **ptr);
long	ft_count_char(char *target, char to_count);
int		limit(char **str, double max, double min);
int		check_vector_l(char *str, double max, double min, long lg);
int		check_vector(char *str, long lg);
double	ft_atof(char *str);
#endif
