/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:11:04 by srheede           #+#    #+#             */
/*   Updated: 2018/08/23 11:24:05 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualizer.h"

void	place_line(t_v *v, int height, int offset, int stack)
{
	int	i;
	int j;
	int c;

	if (stack)
	{
		j = 400;
		c = 0x00FF0000;
	}
	else
	{
		j = 0;
		c = 0x0000FF00;
	}
	while (height)
	{
		i = 0;
		while (i <= (400 / v->n_sorted) - 2)
		{
			mlx_pixel_put(v->disp, v->win, i + offset + j, 900 - height, c);
			i++;
		}
		height--;
	}
}

void	display_a(t_v *v, char **arr)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (arr[i])
	{
		if (ft_atoi(arr[i]))
		{
			y = position(v, arr[i]) * (800 / v->n_sorted);
			x = i * (400 / v->n_sorted);
			place_line(v, y, x, 0);
		}
		i++;
	}
}

void	display_b(t_v *v, char **arr)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (arr[i])
	{
		if (ft_atoi(arr[i]))
		{
			y = position(v, arr[i]) * (800 / v->n_sorted);
			x = i * (400 / v->n_sorted);
			place_line(v, y, x, 1);
		}
		i++;
	}
}

int		display(t_v *v)
{
	char	**arr;

	mlx_clear_window(v->disp, v->win);
	if (v->a_list)
	{
		arr = ft_strsplit(v->a_list->content, ' ');
		display_a(v, arr);
		ft_arrdel(arr);
	}
	if (v->b_list)
	{
		arr = ft_strsplit(v->b_list->content, ' ');
		display_b(v, arr);
		ft_arrdel(arr);
	}
	if (v->a_list->next)
	{
		v->a_list = v->a_list->next;
		v->b_list = v->b_list->next;
	}
	return (0);
}
