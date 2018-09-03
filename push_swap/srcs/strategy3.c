/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:06:02 by srheede           #+#    #+#             */
/*   Updated: 2018/08/28 18:47:44 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	strat1_to_a2(t_p *p)
{
	if (iscross_sorted(p))
	{
		while (p->nb)
			do_pb(p);
	}
	if (p->b[0] > p->b[p->nb - 1] && p->a[0] < p->a[p->na - 1])
		do_rrr(p);
	else if (p->b[0] > p->b[p->nb - 1])
		do_rrb(p);
	else if (p->a[0] < p->a[p->na - 1])
		do_rra(p);
	if (p->a[p->na - 1] > p->a[p->na - 2] && p->b[p->nb - 1] < p->b[p->nb - 2])
		do_ss(p);
	else if (p->a[p->na - 1] > p->a[p->na - 2])
		do_sa(p);
	else if (p->b[p->nb - 1] < p->b[p->nb - 2])
		do_sb(p);
	else
		do_pb(p);
}

void	strat1_to_a(t_p *p)
{
	while (p->nb > 0)
	{
		if (p->na > 1)
			strat1_to_a2(p);
		else
		{
			if (p->b[0] > p->b[p->nb - 1])
				do_rrb(p);
			do_pb(p);
		}
	}
}

void	strat1_to_b2(t_p *p)
{
	if (p->b[0] > p->b[p->nb - 1] && p->a[0] < p->a[p->na - 1])
		do_rrr(p);
	else if (p->b[0] > p->b[p->nb - 1])
		do_rrb(p);
	else if (p->a[0] < p->a[p->na - 1])
		do_rra(p);
	if (p->a[p->na - 1] > p->a[p->na - 2] && p->b[p->nb - 1] < p->b[p->nb - 2])
		do_ss(p);
	else if (p->a[p->na - 1] > p->a[p->na - 2])
		do_sa(p);
	else if (p->b[p->nb - 1] < p->b[p->nb - 2])
		do_sb(p);
	else
		do_pa(p);
}

void	strat1_to_b(t_p *p)
{
	while (p->na > 2)
	{
		if (p->nb > 1)
			strat1_to_b2(p);
		else
		{
			if (p->a[0] < p->a[p->na - 1])
				do_rra(p);
			else if (p->a[p->na - 1] > p->a[p->na - 2])
				do_sa(p);
			else
				do_pa(p);
		}
		if (iscross_sorted(p) || issorted(p))
			break ;
	}
}

void	strat3(t_p *p)
{
	if (!issorted(p))
	{
		if (p->na == 2)
			do_ra(p);
		else
		{
			while (!issorted(p))
			{
				strat1_to_b(p);
				strat1_to_a(p);
			}
		}
	}
}
