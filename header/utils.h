/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:10 by mravelon          #+#    #+#             */
/*   Updated: 2025/01/22 13:05:16 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "stdio.h"
# include "struct.h"

void	ft_filltab(int *tab, int len, int val);
void	ft_replace_str(char *to_change, char *set, char val);
long	ft_count_char(char *target, char to_count);
int		limit(char **str, double max, double min);
int		check_vector_l(char *str, double max, double min, long lg);
int		check_vector(char *str, long lg);
double	ft_atof(char *str);
int		ft_atoi_base(char *arg, int base);
void	ft_free_tab(char **ptr);

void	ft_disp_color(t_color *color);
void	ft_disp_vect(t_vect *vect);
void	ft_disp_content_a(t_a *curr);
void	ft_disp_content_c(t_c *curr);
void	ft_disp_content_l(t_l *curr);


void	*get_type(t_maps *obj, t_obj type);
#endif
