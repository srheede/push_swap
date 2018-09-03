/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:11:04 by srheede           #+#    #+#             */
/*   Updated: 2018/08/28 19:33:43 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_max(t_p *p)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < p->nb)
	{
		if (p->b[i] > max)
			max = p->b[i];
		i++;
	}
	i = 1;
	while (p->b[p->nb - i] != max)
		i++;
	return (i);
}

int		find_min(t_p *p, int max)
{
	int	i;
	int	min;

	i = 0;
	min = max;
	while (i < p->nb)
	{
		if (p->b[i] < min)
			min = p->b[i];
		i++;
	}
	i = 1;
	while (p->b[p->nb - i] != min)
		i++;
	return (i);
}

void	find_next2(t_p *p, int max, int min)
{
	if (ft_abs(p->nb + 1 - min) < ft_abs(min - 1))
	{
		p->min_n = ft_abs(p->nb + 1 - min);
		p->direction_min = 0;
	}
	else
	{
		p->min_n = ft_abs(min - 1);
		p->direction_min = 1;
	}
	if (ft_abs(p->nb + 1 - max) < ft_abs(max - 1))
	{
		p->max_n = ft_abs(p->nb + 1 - max);
		p->direction_max = 0;
	}
	else
	{
		p->max_n = ft_abs(max - 1);
		p->direction_max = 1;
	}
}

void	find_next(t_p *p)
{
	int min;
	int max;

	max = find_max(p);
	min = find_min(p, p->b[max]);
	find_next2(p, max, min);
	if (p->max_n <= p->min_n + 1)
	{
		p->d = p->direction_max;
		p->next = p->b[p->nb - max];
	}
	else
	{
		p->d = p->direction_min;
		p->next = p->b[p->nb - min];
	}
}

void	part_to_a1(t_p *p)
{
	find_next(p);
	if (p->b[p->nb - 1] == p->next && p->shift)
		do_rra(p);
	while (p->b[p->nb - 1] != p->next)
	{
		if (p->d && p->shift)
		{
			do_rrr(p);
			p->shift = 0;
		}
		else if (p->d)
			do_rrb(p);
		else if (p->shift)
		{
			do_rra(p);
			p->shift = 0;
		}
		else
			do_rb(p);
	}
}
