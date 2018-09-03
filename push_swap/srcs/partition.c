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

void	part_to_a(int *sorted, int n_sorted, t_p *p)
{
	if (p->b[p->nb - 1] < p->max)
		do_rrb(p);
	while (p->nb)
	{
		part_to_a1(p);
		if (p->na)
		{
			if (p->b[p->nb - 1] < sorted[n_sorted - 1])
			{
				do_pb(p);
				p->shift = 1;
			}
			else
			{
				do_pb(p);
				n_sorted--;
			}
		}
		else
			do_pb(p);
	}
}

void	find_direction(t_p *p, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((p->a[p->na - 1 - i] < max) && (p->na - 1 - i) >= 0)
		i++;
	while ((p->a[j] < max) && (j < p->na) > 0)
		j++;
	if (i < j + 1)
		p->d = 1;
	else
		p->d = 0;
}

int		partition2(int n_sorted, t_p *p, int max)
{
	if ((p->b[p->nb - 1] > p->max) && p->nb > 0)
		p->max = p->b[p->nb - 1];
	if ((p->b[p->nb - 1] < p->max) && p->a[p->na - 1] < max && p->d)
		do_rrr(p);
	else if ((p->b[p->nb - 1] < p->max) && p->a[p->na - 1] < max && p->d == 0)
		do_ra(p);
	else if ((p->b[p->nb - 1] < p->max))
		do_rrb(p);
	else if (p->a[p->na - 1] >= max)
	{
		do_pa(p);
		n_sorted--;
		find_direction(p, max);
	}
	else if (p->d)
		do_rra(p);
	else
		do_ra(p);
	return (n_sorted);
}

void	partition1(int n_sorted, t_p *p, int max, int tmp)
{
	while (n_sorted - tmp)
	{
		n_sorted = partition2(n_sorted, p, max);
		if (p->na == 0 && p->b[p->nb - 1] == p->max)
			break ;
	}
}

void	partition(int *sorted, int n_sorted, t_p *p)
{
	int		tmp;
	int		max;

	tmp = n_sorted - (n_sorted / 6) - 1;
	max = sorted[tmp];
	find_direction(p, max);
	partition1(n_sorted, p, max, tmp);
	n_sorted = tmp;
	if (p->na != 0)
		partition(sorted, n_sorted, p);
	p->d = 0;
	part_to_a(sorted, p->tmp, p);
	while (p->a[0] != sorted[p->tmp])
		do_ra(p);
}
