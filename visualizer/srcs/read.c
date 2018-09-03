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

void	read_input(t_v *v)
{
	char	*buffer;

	while (get_next_line(0, &buffer))
	{
		if (ft_strchr(buffer, 'A'))
		{
			if (!v->sorted)
				sort(v, buffer);
			v->a_list->next = ft_lstnew(buffer + 8, ft_strlen(buffer + 8));
			v->a_list = v->a_list->next;
		}
		if (ft_strchr(buffer, 'B'))
		{
			if (buffer + 9)
			{
				v->b_list->next = ft_lstnew(buffer + 8, ft_strlen(buffer + 8));
				v->b_list = v->b_list->next;
			}
		}
		ft_strdel(&buffer);
	}
	v->a_list = v->tmp_a->next;
	v->b_list = v->tmp_b->next;
}
