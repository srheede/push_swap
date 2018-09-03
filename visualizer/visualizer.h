/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:43:57 by srheede           #+#    #+#             */
/*   Updated: 2018/08/23 11:24:30 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# include "../libft/libft.h"
# include <libc.h>
# include <mlx.h>

typedef struct		s_v
{
	void			*disp;
	void			*win;
	char			**map;
	int				*sorted;
	int				n_sorted;
	t_list			*a_list;
	t_list			*b_list;
	t_list			*tmp_a;
	t_list			*tmp_b;
}					t_v;

void				sort(t_v *v, char *buffer);
int					position(t_v *v, char *str);
int					display(t_v *v);
void				read_input(t_v *v);

#endif
