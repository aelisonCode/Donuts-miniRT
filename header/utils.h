/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravelon <mravelon@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:10 by mravelon          #+#    #+#             */
/*   Updated: 2025/02/25 14:39:18 by mravelon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "struct.h"

/*Event*/
void	ft_define_base(t_base *to_change, t_command obj, int value);
void	ft_select_event(t_base event[10], t_command to_exec, int do_lock_else);
void	ft_lock_event(t_base event[10], t_command not_lock);
int		ft_get_event_state(t_base event[10], t_command search);
void	ft_protect_event(t_base event[10]);

void	ft_filltab(int *tab, int len, int val);
void	ft_replace_str(char *to_change, char *set, char val);
long	ft_count_char(char *target, char to_count);
int		limit(char **str, double max, double min);
double	ft_atof(char *str);
void	ft_free_tab(char **ptr);
void	ft_disp_color(t_color *color);
void	ft_disp_vect(t_vect *vect);
void	ft_disp_content_a(t_a *curr);
void	ft_disp_content_c(t_c *curr);
void	ft_disp_content_l(t_l *curr);
int		ft_strcmp(char *one, char *two);
int		tab_length(char **str);
int		ft_error(int fd, char **argv, t_scene *data);
int		check_vector(char *str);
int		check_color(char *color);
int		check_rang(char *str, double min, double max);
int		check_vector_rang(char *str, double min, double max);
int		is_valid_format(char *str);
#endif
