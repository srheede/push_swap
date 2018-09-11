/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:11:04 by srheede           #+#    #+#             */
/*   Updated: 2018/08/23 11:24:05 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualizer.h"

int		position(t_v *v, char *str)
{
	int	i;

	i = 0;
	while (i <= v->n_sorted)
	{
		if (v->sorted[i] == ft_atoi(str))
			break ;
		i++;
	}
	return (i);
}

void	read_a(t_v *v, char *buffer)
{
	if (!v->a_list)
	{
		v->a_list = (t_list *)malloc(sizeof(t_list));
		v->b_list = (t_list *)malloc(sizeof(t_list));
		v->tmp_a = v->a_list;
		v->tmp_b = v->b_list;
	}
	if (!v->sorted)
		sort(v, buffer);
	if (ft_strlen(buffer) > 7)
	{
		v->a_list->next = ft_lstnew(buffer + 8, ft_strlen(buffer) - 7);
		v->a_list = v->a_list->next;
	}
}

void	read_b(t_v *v, char *buffer)
{
	if (ft_strlen(buffer) > 7)
	{
		v->b_list->next = ft_lstnew(buffer + 8, ft_strlen(buffer) - 7);
		v->b_list = v->b_list->next;
	}
}

void	read_input(t_v *v)
{
	char	*buffer;

	while (get_next_line(0, &buffer))
	{
		if (ft_strchr(buffer, 'A'))
			read_a(v, buffer);
		if (ft_strchr(buffer, 'B'))
			read_b(v, buffer);
		ft_strdel(&buffer);
	}
	if (v->tmp_a)
		v->a_list = v->tmp_a->next;
	if (v->tmp_b)
		v->b_list = v->tmp_b->next;
}
