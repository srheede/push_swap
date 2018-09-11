/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_op3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srheede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 13:23:00 by srheede           #+#    #+#             */
/*   Updated: 2018/08/27 17:51:50 by srheede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rra(t_p *p)
{
	int	i;
	int	tmp;

	if (p->na > 0)
	{
		tmp = p->a[p->na - 1];
		i = p->na - 1;
		while (i > 0)
		{
			p->a[i] = p->a[i - 1];
			i--;
		}
		p->a[0] = tmp;
		ft_putstr("rra\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
		{
			get_next_line(0, &p->buffer);
			ft_strdel(&p->buffer);
		}
	}
}

void	do_rrb(t_p *p)
{
	int	i;
	int	tmp;

	if (p->nb > 0)
	{
		tmp = p->b[p->nb - 1];
		i = p->nb - 1;
		while (i > 0)
		{
			p->b[i] = p->b[i - 1];
			i--;
		}
		p->b[0] = tmp;
		ft_putstr("rrb\n");
		if (p->debug)
			putstacks(p);
		if (p->step)
		{
			get_next_line(0, &p->buffer);
			ft_strdel(&p->buffer);
		}
	}
}

void	print_rrr(t_p *p)
{
	ft_putstr("rrr\n");
	if (p->debug)
		putstacks(p);
	if (p->step)
	{
		get_next_line(0, &p->buffer);
		ft_strdel(&p->buffer);
	}
}

void	do_rrr(t_p *p)
{
	int	i;
	int	tmp;

	if (p->na > 0 && p->nb > 0)
	{
		tmp = p->a[p->na - 1];
		i = p->na - 1;
		while (i > 0)
		{
			p->a[i] = p->a[i - 1];
			i--;
		}
		p->a[0] = tmp;
		tmp = p->b[p->nb - 1];
		i = p->nb - 1;
		while (i > 0)
		{
			p->b[i] = p->b[i - 1];
			i--;
		}
		p->b[0] = tmp;
		print_rrr(p);
	}
}
