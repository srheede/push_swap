/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:11:04 by srheede           #+#    #+#             */
/*   Updated: 2018/08/23 11:24:05 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visualizer.h"

void	sort(t_v *v, char *buffer)
{
	int		i;
	int		j;
	char	**arr;

	arr = ft_strsplit(buffer, ' ');
	v->sorted = (int *)malloc(sizeof(int) * ft_arrlen(arr));
	i = 0;
	j = 0;
	while (arr[i])
	{
		if (!ft_strstr(arr[i], "Stack") && !ft_strstr(arr[i], "A:"))
		{
			v->sorted[j] = ft_atoi(arr[i]);
			j++;
		}
		free(arr[i]);
		i++;
	}
	quicksort(v->sorted, 0, j);
	v->n_sorted = j;
}

int		hook(int key, t_v *v)
{
	(void)v;
	if (key == 76)
	{
		if (v->b_list->next)
		{
			v->a_list = v->a_list->next;
			v->b_list = v->b_list->next;
		}
	}
	if (key == 53)
		exit(1);
	return (0);
}

void	reset(t_v *v)
{
	v->disp = NULL;
	v->win = NULL;
	v->map = NULL;
	v->sorted = NULL;
	v->n_sorted = 0;
	v->a_list = NULL;
	v->b_list = NULL;
	v->tmp_a = NULL;
	v->tmp_b = NULL;
}

void	clear(t_v *v)
{
	while (v->tmp_a)
	{
		v->a_list = v->tmp_a->next;
		ft_strdel(v->tmp_a->content);
		free(v->tmp_a);
		v->tmp_a = v->a_list;
	}
	while (v->tmp_b)
	{
		v->b_list = v->tmp_b->next;
		ft_strdel(v->tmp_b->content);
		free(v->tmp_b);
		v->tmp_b = v->b_list;
	}
	free(v->sorted);
}

int		main(void)
{
	t_v	v;

	reset(&v);
	v.a_list = (t_list *)malloc(sizeof(t_list));
	v.b_list = (t_list *)malloc(sizeof(t_list));
	v.tmp_a = v.a_list;
	v.tmp_b = v.b_list;
	read_input(&v);
	v.disp = mlx_init();
	v.win = mlx_new_window(v.disp, 900, 900, "push_swap");
	mlx_loop_hook(v.disp, display, &v);
	mlx_key_hook(v.win, hook, &v);
	mlx_loop(v.disp);
	clear(&v);
	return (0);
}
