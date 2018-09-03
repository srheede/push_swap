/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:22:21 by srheede           #+#    #+#             */
/*   Updated: 2018/08/28 15:35:55 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_pa(t_p *p)
{
	if (p->na > 0)
	{
		p->nb++;
		ft_swap(&p->a[p->na - 1], &p->b[p->nb - 1]);
		p->na--;
		ft_putstr("pa\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
			get_next_line(0, &p->buffer);
	}
}

void	do_pb(t_p *p)
{
	if (p->nb > 0)
	{
		p->na++;
		ft_swap(&p->a[p->na - 1], &p->b[p->nb - 1]);
		p->nb--;
		ft_putstr("pb\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
			get_next_line(0, &p->buffer);
	}
}

void	do_ra(t_p *p)
{
	int	i;
	int	tmp;

	if (p->na > 0)
	{
		tmp = p->a[0];
		i = 0;
		while (i < p->na)
		{
			p->a[i] = p->a[i + 1];
			i++;
		}
		p->a[p->na - 1] = tmp;
		ft_putstr("ra\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
			get_next_line(0, &p->buffer);
	}
}

void	do_rb(t_p *p)
{
	int	i;
	int	tmp;

	if (p->nb > 0)
	{
		tmp = p->b[0];
		i = 0;
		while (i < p->nb)
		{
			p->b[i] = p->b[i + 1];
			i++;
		}
		p->b[p->nb - 1] = tmp;
		ft_putstr("rb\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
			get_next_line(0, &p->buffer);
	}
}

void	do_rr(t_p *p)
{
	int	tmp;

	if (p->nb > 0 && p->na > 0)
	{
		tmp = p->b[0];
		p->b++;
		p->b[p->nb - 1] = tmp;
		tmp = p->a[0];
		p->a++;
		p->a[p->na - 1] = tmp;
		ft_putstr("rr\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
			get_next_line(0, &p->buffer);
	}
}
