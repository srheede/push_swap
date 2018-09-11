/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:22:36 by srheede           #+#    #+#             */
/*   Updated: 2018/08/27 18:23:40 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sa(t_p *p)
{
	if (p->na > 1)
	{
		ft_swap(&p->a[p->na - 1], &p->a[p->na - 2]);
		ft_putstr("sa\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
		{
			get_next_line(0, &p->buffer);
			ft_strdel(&p->buffer);
		}
	}
}

void	do_sb(t_p *p)
{
	if (p->nb > 1)
	{
		ft_swap(&p->b[p->nb - 1], &p->b[p->nb - 2]);
		ft_putstr("sb\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
		{
			get_next_line(0, &p->buffer);
			ft_strdel(&p->buffer);
		}
	}
}

void	do_ss(t_p *p)
{
	if (p->na > 1 && p->nb > 1)
	{
		ft_swap(&p->a[p->na - 1], &p->a[p->na - 2]);
		ft_swap(&p->b[p->nb - 1], &p->b[p->nb - 2]);
		ft_putstr("ss\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
		{
			get_next_line(0, &p->buffer);
			ft_strdel(&p->buffer);
		}
	}
}
